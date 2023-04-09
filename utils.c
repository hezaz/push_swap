/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:40:56 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/09 22:15:27 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	ft_exit(t_stack *stack_a)
{
	if (stack_a)
		ft_free_stack(stack_a);
	exit(-1);
	return (-1);
}

int	ft_pushatoi(const char *str, t_stack *stack_a)
{
	int			i;
	int			s;
	int			res2;
	long long	tmp;

	res2 = 0;
	s = 1;
	i = 0;
	tmp = 0;
	while (str && str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if ((str[i] == '+' || str[i] == '-') && str && str[i])
		if (str[i++] == '-')
			s *= (-1);
	while (str && str[i] && (str[i] >= '0' && str[i] <= '9'))
		tmp = (tmp * 10) + (str[i++] - '0');
	if ((tmp > INT_MAX) || (tmp < INT_MIN)
		|| (str[i] && !(str[i] >= '0' && str[i] <= '9')))
		return (ft_exit(stack_a));
	res2 = (int)tmp;
	return (res2 * s);
}


// Swap the top two elements of the stack.
// No action if there's only one or no elements.
void swap(t_stack **stack)
{
	t_stack *temp;

	if (!*stack || !(*stack)->next)
		return;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

// Move the top element of the source stack to the top of the destination stack.
// No action if the source stack is empty.
void push(t_stack **src, t_stack **dst)
{
	t_stack *temp;

	if (!*src)
		return;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

// Shift up all elements of the stack by 1 position.
// The first element becomes the last one.
// No action if there's only one or no elements.
void rotate(t_stack **stack)
{
	t_stack *temp;
	t_stack *last;

	if (!*stack || !(*stack)->next)
		return;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = temp;
}

// Shift down all elements of the stack by 1 position.
// The last element becomes the first one.
// No action if there's only one or no elements.
void reverse_rotate(t_stack **stack)
{
    t_stack *prev;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return;
    prev = NULL;
    last = *stack;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}

int	ft_stksize(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	if (!stack)
		return (i);
	if (!(stack -> next))
		return (++i);
	while (tmp)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}


// Perform sa and sb simultaneously.
void ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
}

// Perform ra and rb simultaneously.
void rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
}

// Perform rra and rrb simultaneously.
void rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
}
