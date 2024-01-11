/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:39:57 by hzaz              #+#    #+#             */
/*   Updated: 2024/01/11 00:42:32 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_get_cost(t_stack **stack_a, t_stack **stack_b)
{
	int	*l;

	if (!(*stack_b))
		return ;

	//ft_print_stack(stack_a, stack_b, ft_stksize(*stack_b));
	get_cost(stack_a);
	get_cost(stack_b);
	l = get_absolute_cost(stack_a, stack_b);
	find_best_op(stack_a, stack_b, l);
}

void	get_cost(t_stack **stack)
{
	t_stack			*tmp;
	int				len;

	len = ft_stksize(*stack);
	ft_get_pos(*stack);
	if (len == 0)
		return ;
	else if (len == 1)
		(*stack)->cost = 0;
	else if (len == 2)
	{
		(*stack)->cost = 0;
		(*stack)->next->cost = 1;
	}
	else if (len == 3)
	{
		(*stack)->cost = 0;
		(*stack)->next->cost = 1;
		(*stack)->next->next->cost = -1;
	}
	tmp = *stack;
	while (tmp)
	{
		if ((tmp->pos - 1) > len / 2)
			tmp->cost= tmp->pos - len - 1;
		else
			tmp->cost = tmp->pos - 1;
		tmp = tmp->next;
	}
}

int		*get_absolute_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	int rota_cpt;
	//int rotb_cpt;
	if (!(*stack_b))
			return NULL;
	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_a = *stack_a;
		rota_cpt = 0;
		if (tmp_a->index > tmp_b->index && ft_stklast(&tmp_a)->index < tmp_b->index)
			rota_cpt = tmp_a->cost;
		else
		{
			while (tmp_a)
			{

				if ((tmp_a && tmp_a->next) && tmp_a->index < tmp_b->index
					&& tmp_a->next->index > tmp_b->index)
				{
						rota_cpt = tmp_a->next->cost;
						tmp_a = tmp_a->next;
						break ;
				}
				tmp_a = tmp_a->next;

			}
		}
		if (( rota_cpt >= 0 && tmp_b->cost >= 0))
		{
			if (rota_cpt >= tmp_b->cost)
				tmp_b->absolute_cost = rota_cpt;
			else
				tmp_b->absolute_cost = tmp_b->cost;
		}
		else if (rota_cpt < 0 && tmp_b->cost < 0)
		{
			if (rota_cpt < tmp_b->cost)
				tmp_b->absolute_cost = (rota_cpt * (-1));
			else
				tmp_b->absolute_cost = (tmp_b->cost * (-1));
		}
		else
		{
			if (rota_cpt < 0)
				tmp_b->absolute_cost = (rota_cpt * (-1)) + tmp_b->cost;
			else if (tmp_b->cost < 0)
				tmp_b->absolute_cost = (tmp_b->cost * (-1)) + rota_cpt;
		}
		tmp_b=tmp_b->next;

	}
	return (&tmp_a->cost);

}


void find_best_op(t_stack **stack_a,t_stack **stack_b,int *rota_cpt)
{
	t_stack		*tmp_b;
	int			rot_b;
	int			cpr;

	if (!(*stack_b))
		return;
	tmp_b = *stack_b;
	cpr = tmp_b->absolute_cost;
	rot_b = 0;
	while (tmp_b)
	{
		if (tmp_b->absolute_cost < cpr)
		{
			cpr = tmp_b->absolute_cost;
			rot_b = tmp_b->cost;
			break ;
		}
		tmp_b = tmp_b->next;
	}
	//ft_printf("\n pos = %d\n cpr = %d\n", rot_b, cpr);
	//if (!stack_a)
	//	*rota_cpt = ft_atoi("1233");
	ft_pushwap(stack_a, stack_b, rota_cpt, &rot_b);

}

void	ft_pushwap(t_stack **stack_a, t_stack **stack_b, int *rota, int *rotb)
{

	t_stack *tmp_b;
	

	tmp_b = *stack_b;
	if (!tmp_b)
		return ; ///////// LEAKS LEAKS LEAKS LEAKS LEAKS STACK A & B NO FREED have to impkement ft_error with stack a and b and not just stack a

	while (*rota != 0 || *rotb != 0)
	{
		if ((*rota > 0 && *rotb <= 0) || (*rota < 0 && *rotb >= 0))
			ft_rotate(stack_a, rota, 'a');
		else if ((rotb < 0 && rota >= 0) || (rotb > 0 && rota <= 0))
			ft_rotate(stack_b, rotb, 'b');
		else if ((rota > 0 && rotb > 0 )||(rota < 0 && rotb < 0))
			ft_rr(stack_a, stack_b, rota, rotb);

	}
	ft_push(stack_b, stack_a,'a');
	//get_cost(stack_a);
	//get_cost(stack_b);
	//int l = get_absolute_cost(stack_a, stack_b);
	//find_best_op(stack_a, stack_b, &l);
	//ft_print_stack(stack_a, stack_b, ft_stksize(*stack_b));
	ft_get_cost(stack_a, stack_b);

}

