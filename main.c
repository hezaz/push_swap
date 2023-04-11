/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:30:25 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/11 02:32:11 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	t_stack	*stack_c;
	int i = 0;
	int j = 0;

	stack_b = NULL;
	stack_a = NULL;
	if (ac == 1 )
		return 0;

	*stack_a = get_stack(av, *stack_a, ac);
	ft_get_index_final(*stack_a);
	first_sort(stack_a, stack_b);
	ft_get_cost(stack_a, stack_b);
	t_stack *tmp_b2 = *stack_b;
	while (tmp_b2)
	{
		ft_get_cost(stack_a, stack_b);
		tmp_b2=tmp_b2->next;
	}

	//get_absolute_cost(stack_a, stack_b);
	stack_c = *stack_a;
	printf("\n\n\n****************************\n");
	printf("****************************\n");
	printf("*********STACK_A :**********\n");
	printf("****************************\n");
	printf("****************************\n\n\n\n\n");
	while (stack_c && ++i)
	{
		printf("\n\n");
		printf("*************stack_a numero: %d***************\n", i);
		printf("  value = %d\npos = %d\nindex = %d\nindex_max = %d\nindex_min = %d\ncost = %d\n", stack_c->value, stack_c->pos, stack_c->index, stack_c->index_max, stack_c->index_min, stack_c->cost);
		printf("****************************\n\n\n");
		stack_c = stack_c->next;
	}
	printf("\n\n\n****************************\n");
	printf("****************************\n");
	printf("*********STACK_B :**********\n");
	printf("****************************\n");
	printf("****************************\n\n\n\n\n");
	stack_c = *stack_b;
	while (stack_c && ++j)
	{
		printf("\n\n");
		printf("**************stack_b numero: %d**************\n", j);
		printf("value = %d\npos = %d\nindex = %d\nindex_max = %d\nindex_min = %d\ncost = %d\nabsolute_cose = %d\n", stack_c->value, stack_c->pos, stack_c->index, stack_c->index_max, stack_c->index_min, stack_c->cost, stack_c->absolute_cost);
		printf("****************************\n");
		stack_c = stack_c->next;
	}
	ft_free_stack(*stack_a);
	ft_free_stack(*stack_b);

	int k = 0;
	int h = -0;
	printf("\n\n\n k = %d && h = %d\n\n\n", k, h);
	return (0);
}
