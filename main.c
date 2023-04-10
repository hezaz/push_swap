/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:30:25 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/10 03:51:03 by hzaz             ###   ########.fr       */
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
	(*ret).index = pos;
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

void ft_get_index_final(t_stack *stack)
{
	int swap;
	t_stack *tmp;
	t_stack *tmp2;

	tmp = stack;
	//tmp2 = stack->next;
	while(tmp)
	{
		tmp2 = tmp;
		while(tmp2)
		{
			int tmp1_value = tmp->value;
			int tmp2_value = tmp2->value;
			int tmp1_index = tmp->index;
			int tmp2_index = tmp2->index;
			if ((tmp->value > tmp2->value && tmp->index < tmp2->index)
				|| (tmp->value < tmp2->value && tmp->index > tmp2->index))
			{
				swap = tmp->index;
				tmp->index = tmp2->index;
				tmp2->index = swap;
				int tmp1_index_final= tmp->index;
				int tmp2_index_final= tmp2->index;
			}

			tmp2 = tmp2->next;
		}
		tmp=tmp->next;
	}
	get_index_max_min(stack);
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
		if ((*stack_a)->index == (*stack_a)->index_max || (*stack_a)->index == (*stack_a)->index_min)
			rotate(stack_a);
		// Find the first element with indice >= threshold and count rotations required
		else
		{
			while (tmp && tmp->index < threshold )
			{
				rot_count++;
				if (tmp->next->index == tmp->index_max || tmp->next->index == tmp->index_min)
				{
					tmp = tmp->next->next;
					rot_count++;
				}
				else
					tmp = tmp->next;
			}

			// If the tmp reaches the end of stack_a, all elements meeting the condition are already in stack_b
			if (!tmp)
				break;
			// Rotate stack_a until the element with the target indice is at the top (if not already there)
			while (rot_count-- > 0)
				rotate(stack_a);
			// Push the element from stack_a to stack_b
			//if (tmp->index != tmp->index_max || tmp->index != tmp->index_min)
			push(stack_a, stack_b);
			//else
			//	rotate(stack_a);

		}
		elements_left--;
	}
}


//void first_sort(t_stack **stack_a, t_stack **stack_b)
//{
//	int len;
//	int threshold;
//	t_stack *tmp;
//	int rot_count;
//	int elements_left;

//	len = ft_stksize(*stack_a);
//	threshold = (2 * len) / 3;
//	elements_left = len - 1;
//	while (elements_left > 0)
//	{
//		if ((*stack_a)->index == (*stack_a)->index_max && (*stack_a)->index == (*stack_a)->index_min)
//		{
//			rotate(stack_a);
//			continue;
//		}
//		tmp = *stack_a;
//		rot_count = 0;
//		// Find the first element with index >= threshold and count rotations required
//		while (tmp && tmp->index < threshold)
//		{
//			rot_count++;
//			tmp = tmp->next;
//		}
//		// If the tmp reaches the end of stack_a, all elements meeting the condition are already in stack_b
//		if (!tmp)
//			break;
//		// Rotate stack_a until the element with the target index is at the top (if not already there)
//		while (rot_count-- > 0 && (*stack_a)->index != (*stack_a)->index_max && (*stack_a)->index != (*stack_a)->index_min)
//			rotate(stack_a);
//		// Push the element from stack_a to stack_b
//		if ((*stack_a)->index != (*stack_a)->index_max && (*stack_a)->index != (*stack_a)->index_min)
//		{
//			push(stack_a, stack_b);
//			elements_left--;
//		}
//		else
//			rotate(stack_a);



//	}
//	second_sort(stack_a, stack_b);
//}

//void second_sort(t_stack **stack_a, t_stack **stack_b)
//{
//    int len;
//    int threshold;
//    t_stack *tmp;
//    int rot_count;
//    int elements_left;

//    len = ft_stksize(*stack_a);
//    threshold = len / 2;
//    elements_left = len ;
//    while (elements_left > 0)
//    {
//		if ((*stack_a)->index == (*stack_a)->index_max && (*stack_a)->index == (*stack_a)->index_min)
//		{
//			rotate(stack_a);
//			continue;
//		}
//		if ((*stack_a)->index != (*stack_a)->index_max && (*stack_a)->index != (*stack_a)->index_min)
//		{
//			tmp = *stack_a;
//			rot_count = 0;
//			// Find the first element with index >= threshold and count rotations required
//			while (tmp && tmp->index <= threshold)
//			{
//				rot_count++;
//				tmp = tmp->next;
//			}
//			// If the tmp reaches the end of stack_a, all elements meeting the condition are already in stack_b
//			if (!tmp)
//				break;
//			// Rotate stack_a until the element with the target index is at the top
//			while (rot_count-- > 0 && (*stack_a)->index != (*stack_a)->index_max && (*stack_a)->index != (*stack_a)->index_min)
//				rotate(stack_a);
//			// Push the element from stack_a to stack_b
//			if ((*stack_a)->index != (*stack_a)->index_max && (*stack_a)->index != (*stack_a)->index_min)
//			{
//				push(stack_a, stack_b);
//				elements_left--;
//			}
//			else
//				rotate(stack_a);
//		}
//		else
//			rotate(stack_a);


//    }
//	third_sort(stack_a, stack_b);
//}

//void	third_sort(t_stack **stack_a, t_stack **stack_b)
//{
//	int		len;
//	int		elements_left;

//	len = ft_stksize(*stack_a);
//	elements_left = 0;
//	while (elements_left < len - 1)
//	{
//		if ((*stack_a)->index == (*stack_a)->index_max && (*stack_a)->index == (*stack_a)->index_min)
//		{
//			rotate(stack_a);
//			continue;
//		}
//		if ((*stack_a)->index != (*stack_a)->index_max && (*stack_a)->index != (*stack_a)->index_min)
//		{
//			if ((*stack_a)->index != (*stack_a)->index_min && (*stack_a)->index != (*stack_a)->index_max)
//			{
//				push(stack_a, stack_b);
//				elements_left++;
//			}
//			else
//				rotate(stack_a);
//		}
//		else
//			rotate(stack_a);
//	}
//	if ((*stack_a)->index == (*stack_a)->index_max && ((*stack_a)->next)->index ==(*stack_a)->index_min && !((*stack_a)->next)->next)
//			rotate(stack_a);
//}



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
	ft_get_index_final(stack_a);
	first_sort(&stack_a, &stack_b);
	stack_c = stack_a;
	printf("\n stack_a :\n");
	while (stack_c)
	{
		printf("\nvalue = %d\npos = %d\nindex = %d\nindex_max = %d\nindex_min = %d\n", stack_c->value, stack_c->pos, stack_c->index, stack_c->index_max, stack_c->index_min);
		stack_c = stack_c->next;
	}
	printf("\n stack_b :\n");
	stack_c = stack_b;
	while (stack_c)
	{
		printf("\nvalue = %d\npos = %d\nindex = %d\nindex_max = %d\nindex_min = %d\n", stack_c->value, stack_c->pos, stack_c->index, stack_c->index_max, stack_c->index_min);
		stack_c = stack_c->next;
	}
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
