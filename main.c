/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:30:25 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/09 20:44:06 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
t_stack	*ft_stknew(int value)
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	(*ret).value = value;
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
			ft_stkadd_back(&stack_a, ft_stknew(num));
		if (!stack_a)
			stack_a = ft_stknew(num);
		i++;
	}
	if ((av[i]) && (stack_a))
	{
		ft_free_stack(stack_a);
		return NULL;
	}
	return (stack_a);
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
	stack_b = stack_a;
	while (stack_b)
	{
		printf("\n%d\n", stack_b->value);
		stack_b = stack_b->next;
	}
	ft_free_stack(stack_a);
	return (0);
}
