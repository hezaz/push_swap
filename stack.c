/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:34:23 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/12 16:24:50 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

t_stack	*ft_stknew(int value, int pos)
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	(*ret).value = value;
	(*ret).pos = pos;
	(*ret).index = pos;
	(*ret).cost = 0;
	ret->next = NULL;
	return (ret);
}

void	check_stkdouble(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*cur;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		cur = tmp->next;
		while (cur)
		{
			if (tmp->value == cur->value)
				ft_exit(*stack);
			cur = cur->next;
		}
		tmp = tmp->next;
	}
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

	if (!new)
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

t_stack	*get_stack(char **av, t_stack *stack_a, int ac)
{
	int	i;
	int	num;

	i = 1;
	while (av[i] && *av[i])
	{
		num = ft_pushatoi(av[i], stack_a);
		ft_stkadd_back(&stack_a, ft_stknew(num, i));
		i++;
	}
	check_stkdouble(&stack_a);
	if (i != ac)
	{
		ft_free_stack(stack_a);
		return NULL;
	}
	return (stack_a);
}