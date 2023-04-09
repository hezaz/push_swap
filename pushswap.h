/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:47:43 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/09 21:07:14 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
    int value;
	int indice;
	int pos;
	int cost;              // The value of the element.
    struct s_stack *next;   // Pointer to the next element in the stack.
} 	t_stack;

int			*parse_input(int argc, char **argv);
void		sort_stack(int *stack_a);
// void		print_instructions();
void		t_get_indice_final(t_stack stack);
t_stack		*ft_stknew(int value, int pos);
void		ft_free_stack(t_stack *stack);
int			main(int ac, char **av);
void		swap(t_stack **stack);
void		push(t_stack **src, t_stack **dst);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
int			ft_pushatoi(const char *str, t_stack *stack_a);
void		rrr(t_stack **stack_a, t_stack **stack_b);

#endif