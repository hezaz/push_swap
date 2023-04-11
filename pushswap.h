/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:47:43 by hzaz              #+#    #+#             */
/*   Updated: 2023/04/11 23:16:58 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
    int value;
	int index;
	int index_max;
	int index_min;
	int pos;
	int cost;
	int	absolute_cost;
    struct s_stack *next;
} 	t_stack;

int			*parse_input(int argc, char **argv);
void		sort_stack(int *stack_a);
// void		print_instructions();
void		ft_mini_sort(t_stack **stack_a);
void		ft_get_index_final(t_stack *stack_a);
void		get_index_max_min(t_stack *stack);
t_stack		*get_stack(char **av, t_stack *stack_a, int ac);
void		get_cost(t_stack **stack);
void		ft_get_cost(t_stack **stack_a, t_stack **stack_b);
void		third_sort(t_stack **stack_a, t_stack **stack_b);
void		first_sort(t_stack **stack_a, t_stack **stack_b);
int			ft_stksize(t_stack *stack);
int			ft_exit(t_stack *stack_a);
void		check_stkdouble(t_stack **stack);
void		second_sort(t_stack **stack_a, t_stack **stack_b);
t_stack		**ft_create_b(void);
void		ft_pushwap(t_stack **stack_a, t_stack **stack_b, int *rota_cpt, int *i);
void	 	find_best_op(t_stack **stack_a,t_stack **stack_b,int *rota_cpt);
t_stack		*ft_stknew(int value, int pos);
void		ft_free_stack(t_stack *stack);
void		ft_get_pos(t_stack **stack);
int			*get_absolute_cost(t_stack **stack_a, t_stack **stack_b);
void ft_print_stack(t_stack **stack_a,t_stack **stack_b, int i);
int			main(int ac, char **av);
void		swap(t_stack **stack);
void		push(t_stack **src, t_stack **dst);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
int			ft_pushatoi(const char *str, t_stack *stack_a);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		ft_push(t_stack **src, t_stack **dst, char c);
void		ft_rotate(t_stack **stack, int *i, char c);
void		ft_reverse_rotate(t_stack **stack, int *i, char c);
void		ft_rr(t_stack **stack_a, t_stack **stack_b, int *i, int *j);
t_stack		*ft_stklast(t_stack **stack);

#endif