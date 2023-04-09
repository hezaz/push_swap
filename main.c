/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:30:25 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/09 23:31:18 by hzaz             ###   ########.fr       */
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

void first_sort(t_stack **stack_a, t_stack **stack_b)
{
	int len;
	int threshold;
	t_stack *tmp;
	int rot_count;
	int elements_left;

	len = ft_stksize(*stack_a);
	threshold = (2 * len) / 3;
	elements_left = len;
	while (elements_left > 0)
	{
		tmp = *stack_a;
		rot_count = 0;
		// Find the first element with indice >= threshold and count rotations required
		while (tmp && tmp->indice < threshold)
		{
			rot_count++;
			tmp = tmp->next;
		}
		// If the tmp reaches the end of stack_a, all elements meeting the condition are already in stack_b
		if (!tmp)
			break;
		// Rotate stack_a until the element with the target indice is at the top (if not already there)
		while (rot_count-- > 0)
			rotate(stack_a);
		// Push the element from stack_a to stack_b
		push(stack_a, stack_b);
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
        while (tmp && tmp->indice <= threshold)
        {
            rot_count++;
            tmp = tmp->next;
        }
        // If the tmp reaches the end of stack_a, all elements meeting the condition are already in stack_b
        if (!tmp)
            break;
        // Rotate stack_a until the element with the target indice is at the top
        while (rot_count-- > 0)
            rotate(stack_a);
        // Push the element from stack_a to stack_b
        push(stack_a, stack_b);
        elements_left--;
    }
}




int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_c;

	stack_b = NULL;
	stack_a = NULL;
	if (ac < 2)
	{
		ft_printf("exec with args");
		return (0);
	}
	stack_a = get_stack(av, stack_a);
	ft_get_indice_final(stack_a);
	first_sort(&stack_a, &stack_b);
	stack_c = stack_a;
	printf("\n stack_a :\n");
	while (stack_c)
	{
		printf("\nvalue = %d\npos = %d\nindice = %d\n", stack_c->value, stack_c->pos, stack_c->indice);
		stack_c = stack_c->next;
	}
	printf("\n stack_b :\n");
	stack_c = stack_b;
	while (stack_c)
	{
		printf("\nvalue = %d\npos = %d\nindice = %d\n", stack_c->value, stack_c->pos, stack_c->indice);
		stack_c = stack_c->next;
	}
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
