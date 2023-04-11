/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:39:57 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/11 02:05:54 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_get_cost(t_stack **stack_a, t_stack **stack_b)
{
	get_cost(stack_a);
	get_cost(stack_b);
	get_absolute_cost(stack_a, stack_b);
}

void	get_cost(t_stack **stack)
{
	t_stack			*tmp;
	int				len;
	//int				limint;

	len = ft_stksize(*stack);
	ft_get_pos(stack);
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
		if ((tmp->pos - 1) > len/2)
			tmp->cost= tmp->pos - len - 1;
		else
			tmp->cost = tmp->pos - 1;
		tmp = tmp->next;
	}

}

void	get_absolute_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	int rota_cpt;
	//int rotb_cpt;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		while (tmp_a)
		{
			if (tmp_b->index < tmp_a->index)
				break ;
			tmp_a=tmp_a->next;
		}
		if (!tmp_a)
			return ; ///////// LEAKS LEAKS LEAKS LEAKS LEAKS STACK A & B NO FREED have to impkement ft_error with stack a and b and not just stack a
		rota_cpt = tmp_a->cost;
		if (rota_cpt == 0)
			tmp_b->absolute_cost = tmp_b->cost;
		else if (tmp_b->cost == 0)
			tmp_b->absolute_cost = rota_cpt;
		else if ((rota_cpt < 0 && tmp_b->cost < 0 ) || ( rota_cpt > 0 && tmp_b->cost > 0))
		{
			if (rota_cpt > tmp_b->cost)
				tmp_b->absolute_cost = rota_cpt - tmp_b->cost;
			else if (rota_cpt < tmp_b->cost)
				tmp_b->absolute_cost = tmp_b->cost - rota_cpt;
			else if (rota_cpt == tmp_b->cost)
				tmp_b->absolute_cost = tmp_b->cost;
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

	find_best_op(stack_a, stack_b, &rota_cpt);
}


void find_best_op(t_stack **stack_a,t_stack **stack_b,int *rota_cpt)
{
	t_stack		*tmp_b;
	int			pos;
	int			cpr;

	tmp_b = *stack_b;
	cpr = tmp_b->absolute_cost;
	while (tmp_b)
	{
		if (tmp_b->absolute_cost < cpr)
		{
			cpr = tmp_b->absolute_cost;
			pos = tmp_b->pos;
		}
		tmp_b = tmp_b->next;
	}
	ft_pushwap(stack_a, stack_b, rota_cpt, &pos);

}

void	ft_pushwap(t_stack **stack_a, t_stack **stack_b, int *rota_cpt, int *pos)
{
	int rotb;
	int rota;
	t_stack *tmp_b;
	//t_stack *tmp_a;

	tmp_b = *stack_b;
	while (tmp_b && tmp_b->pos != *pos)
		tmp_b = tmp_b->next;
	if (!tmp_b)
		return ; ///////// LEAKS LEAKS LEAKS LEAKS LEAKS STACK A & B NO FREED have to impkement ft_error with stack a and b and not just stack a
	rotb = tmp_b->cost;
	rota = *rota_cpt;
	if (rota == 0)
		ft_rotate(stack_b, rotb, 'b');
	else if (rotb == 0)
		ft_rotate(stack_b, rota, 'a');
	else if ((rota < 0 && rotb < 0 )||( rota> 0 && rotb > 0))
	{
		if (rota > rotb)
		{
			ft_rr(stack_a, stack_b, rotb);
			ft_rotate(stack_a, rota-rotb, 'a');
		}

		else if (rota < rotb)
		{
			ft_rr(stack_a, stack_b, rota);
			ft_rotate(stack_b, rotb-rota, 'b');
		}
		else if (rota == rotb)
			ft_rr(stack_a, stack_b, rota);

	}
	else
	{
		ft_rotate(stack_a, rota, 'a');
		ft_rotate(stack_b, rotb, 'b');
	}
	push(stack_b, stack_a);

}

