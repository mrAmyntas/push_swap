/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:39:05 by basz          #+#    #+#                 */
/*   Updated: 2022/10/22 21:19:44 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int	x;
	int	*stack_a;
	int	*stack_b;
	int	*ranking;
	int	*array;
	int	stack_a_len;
	int	stack_b_len;
	int	i;
	int	m_len;
	int	**chunk;
}		t_data;

typedef struct s_positions
{
	int	a;
	int	b;
	int	x;
}		t_positions;

void	ft_check_array(char **argv, int x);
void	ft_error(void);
int		*ft_make_int_array(char **numbers, int len, int x);
int		ft_array_size(char **numbers, int x);
void	ft_small_to_big(t_data *data);
void	ft_operation_sa(t_data *data);
void	ft_operation_sb(t_data *data);
void	ft_operation_pa(t_data *data);
void	ft_operation_pb(t_data *data);
void	ft_operation_ra(t_data *data);
void	ft_operation_rb(t_data *data);
void	ft_operation_rra(t_data *data);
void	ft_operation_rrb(t_data *data);
void	ft_rotate_left(t_data *data, int i);
void	ft_rotate_right(t_data *data, int i);
int		ft_check_a(t_data *data);
int		ft_calc_len_from_mid(t_positions *positions, int x, int y);
void	ft_rotate_push(t_positions *positions, t_data *data, int b);
void	ft_simple(t_data *data, int x);
void	ft_set_pos(t_positions *positions, t_data *data, int size);
void	ft_sort_chunks(t_data *data, int size, int a, int b);
int		ft_chunk(t_data *data, int size, int i, int j);
int		ft_check_b(t_data *data, int a);
void	ft_reset_b(t_data *data);
void	ft_rotate_to_top(t_data *data, int i, int x);
void	ft_rb_or_rrb(t_data *data, int a, int i, int j);
void	ft_rotate_b_back(t_data *data, int i);

#endif
