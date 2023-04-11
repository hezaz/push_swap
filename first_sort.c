/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:31:43 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/11 01:24:18 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void first_sort(t_stack **stack_a, t_stack **stack_b)
{
    int len;
    int threshold;
    t_stack *tmp;
    int rot_count;
    int elements_left;

    len = ft_stksize(*stack_a);
    threshold = ((2 * len) / 3);
    elements_left = len;
    while (elements_left > 0)
    {
        tmp = *stack_a;
        rot_count = 0;

        // Find the first element with indice >= threshold and count rotations required
        while (tmp && tmp->index < threshold )
        {
            rot_count++;
            tmp = tmp->next;
        }

        // If the tmp reaches the end of stack_a, all elements meeting the condition are already in stack_b
        if (!tmp)
            break;

        // Rotate stack_a until the element with the target indice is at the top (if not already there)
        while (rot_count-- > 0)
            ft_rotate(stack_a, 1, 'a');

        // If the element's index is equal to index_max or index_min, rotate stack_a instead of pushing to stack_b
        if ((*stack_a)->index == (*stack_a)->index_max || (*stack_a)->index == (*stack_a)->index_min)
        {
            ft_rotate(stack_a, 1, 'a');
        }
        else
        {
            // Push the element from stack_a to stack_b
            push(stack_a, stack_b);
        }

        elements_left--;
    }
	second_sort(stack_a, stack_b);
}


void second_sort(t_stack **stack_a, t_stack **stack_b)
{
    int len;
    int threshold;
    t_stack *tmp;
    int rot_count;
    int elements_left;

    len = ft_stksize(*stack_a);
    threshold = len / 2;
    elements_left = len;
    while (elements_left > 0)
    {
        tmp = *stack_a;
        rot_count = 0;

        // Find the first element with indice >= threshold and count rotations required
        while (tmp && tmp->index < threshold)
        {
            rot_count++;
            tmp = tmp->next;
        }

        // If the tmp reaches the end of stack_a, all elements meeting the condition are already in stack_b
        if (!tmp)
            break;

        // Rotate stack_a until the element with the target indice is at the top (if not already there)
        while (rot_count-- > 0)
            ft_rotate(stack_a, 1, 'a');

        // If the element's index is equal to index_max or index_min, rotate stack_a instead of pushing to stack_b
        if ((*stack_a)->index == (*stack_a)->index_max || (*stack_a)->index == (*stack_a)->index_min)
        {
            ft_rotate(stack_a, 1 , 'a');
        }
        else
        {
            // Push the element from stack_a to stack_b
            push(stack_a, stack_b);
        }

        elements_left--;
    }
	third_sort(stack_a, stack_b);
}


void	third_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		len;
	int		elements_left;

	len = ft_stksize(*stack_a);
	elements_left = len;
	while (elements_left > 0)
	{
        if ((*stack_a)->index == (*stack_a)->index_max || (*stack_a)->index == (*stack_a)->index_min)
        {
            ft_rotate(stack_a, 1, 'a');
        }
        else
        {
            // Push the element from stack_a to stack_b
            push(stack_a, stack_b);
        }

        elements_left--;
	}
	ft_get_pos(stack_a);
	ft_get_pos(stack_b);
	ft_mini_sort(stack_a);
}

void	ft_mini_sort(t_stack **stack_a)
{
	if ((*stack_a) && ((*stack_a)->next ))
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			ft_rotate(stack_a,1,'a');
	}

}