/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:35:14 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/12 00:09:11 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_get_index_final(t_stack *stack_a)
{
	t_stack *current;
	t_stack *runner;
	int final_index;

	current = stack_a;
	while (current != NULL)
	{
		final_index = -1;
		runner = stack_a;
		while (runner != NULL)
		{
			if (runner->value <= current->value)
			{
				final_index++;
			}
			runner = runner->next;
		}
		current->index = final_index;
		current = current->next;
	}
	get_index_max_min(stack_a);
}


void	get_index_max_min(t_stack *stack)
{
	t_stack *tmp;
	int max;
	int min;

	max = stack->index;
	min = stack->index;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		tmp->index_max = max;
		tmp->index_min = min;
		tmp = tmp->next;
	}
}



void	ft_get_pos(t_stack *stack)
{
	t_stack	*tmp;
	int		cpt;

	tmp = stack;
	cpt = 0;
	while(++cpt && tmp)
	{
		tmp->pos = cpt;
		tmp = tmp->next;
	}
}