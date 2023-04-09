/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:30:25 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/09 21:11:15 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
t_stack	*ft_stknew(int value, int pos)
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	(*ret).value = value;
	(*ret).pos = pos;
	(*ret).indice = pos;
	(*ret).cost = 0;
	ret->next = NULL;
	return (ret);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	ft_stkadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
	return ;
}


t_stack	*get_stack(char **av, t_stack *stack_a)
{
	int	i;
	int	num;

	i = 1;
	while (av[i] && *av[i])
	{
		num = ft_pushatoi(av[i], stack_a);
		if (stack_a)
			ft_stkadd_back(&stack_a, ft_stknew(num, i));
		if (!stack_a)
			stack_a = ft_stknew(num, i);
		i++;
	}
	if ((av[i]) && (stack_a))
	{
		ft_free_stack(stack_a);
		return NULL;
	}
	return (stack_a);
}

void ft_get_indice_final(t_stack *stack)
{
	int swap;
	t_stack *tmp;
	t_stack *tmp2;

	tmp = stack;
	tmp2 = stack->next;
	while(tmp)
	{
		tmp2 = tmp->next;
		while(tmp2)
		{
			if ((tmp->value > tmp2->value && tmp->indice < tmp2->indice)
				|| (tmp->value < tmp2->value && tmp->indice > tmp2->indice))
			{
				swap = tmp->indice;
				tmp->indice = tmp2->indice;
				tmp2->indice = swap;
			}
			tmp2 = tmp2->next;
		}
		tmp=tmp->next;
	}
}

int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	if (ac < 2)
	{
		ft_printf("exec with args");
		return (0);
	}
	stack_a = get_stack(av, stack_a);
	ft_get_indice_final(stack_a);
	stack_b = stack_a;
	while (stack_b)
	{
		printf("\nvalue = %d\npos = %d\nindice = %d\n", stack_b->value, stack_b->pos, stack_b->indice);
		stack_b = stack_b->next;
	}
	ft_free_stack(stack_a);
	return (0);
}
