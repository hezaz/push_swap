/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:30:25 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/11 23:29:15 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_print_stack(t_stack **stack_a,t_stack **stack_b, int i)
{
	t_stack *stack_c;
	if (i == -1)
	{
		return ;
	}


	stack_c = *stack_a;

	printf("*********STACK_A :**********\n");

	while (stack_c)
	{

		printf("*************stack_a pos: %d,***************\n", stack_c->pos);
		printf("  value = %d\npos = %d\nindex = %d\nindex_max = %d\nindex_min = %d\ncost = %d\n", stack_c->value, stack_c->pos, stack_c->index, stack_c->index_max, stack_c->index_min, stack_c->cost);
		printf("****************************\n\n");

		stack_c = stack_c->next;
	}

	printf("*********STACK_B :**********\n");

	stack_c = *stack_b;
	while (stack_c)
	{

		printf("**************stack_b pos: %d**************\n", stack_c->pos);
		printf("value = %d\npos = %d\nindex = %d\nindex_max = %d\nindex_min = %d\ncost = %d\nabsolute_cose = %d\n", stack_c->value, stack_c->pos, stack_c->index, stack_c->index_max, stack_c->index_min, stack_c->cost, stack_c->absolute_cost);
		printf("****************************\n");

		stack_c = stack_c->next;
	}
}


int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;



	if (ac == 1 )
		return 0;
	stack_b = NULL;
	stack_a = NULL;
	stack_a = get_stack(av, stack_a, ac);
	ft_get_index_final(stack_a);
	first_sort(&stack_a, &stack_b);
	int i = 0;
	//printf("*****************************STACK A & B initial*********************************\n");
	//ft_print_stack(&stack_a, &stack_b, i);
	//printf("*****************************STACK A & B initial*********************************\n\n\n");

	ft_get_cost(&stack_a, &stack_b);

	//if (stack_b)
	//{
	//	ft_get_cost(&stack_a, &stack_b);
	//}

	//get_absolute_cost(stack_a, stack_b);
	//printf("*****************************STACK A & B final*********************************\n");
	//ft_print_stack(&stack_a, &stack_b, 0);
	//printf("*****************************STACK A & B final*********************************\n\n\n\n");
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);

	return (0);
}
