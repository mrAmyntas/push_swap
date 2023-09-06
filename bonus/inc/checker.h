/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:39:05 by basz          #+#    #+#                 */
/*   Updated: 2021/10/24 13:39:40 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include "../../libft/libft.h"

typedef struct s_data
{
	int		i;
	int		x;
	int		z;
	int		*stack_a;
	int		*stack_b;
	int		stack_a_len;
	int		stack_b_len;
	char	*line;
}			t_data;

int		get_next_line(char **line);
int		ft_operations(char **array, t_data *data, int i, int x);
void	ft_operation_sa(t_data *data);
void	ft_operation_sb(t_data *data);
void	ft_operation_ss(t_data *data);
void	ft_operation_pa(t_data *data);
void	ft_operation_pb(t_data *data);
void	ft_operation_ra(t_data *data);
void	ft_operation_rb(t_data *data);
void	ft_operation_rr(t_data *data);
void	ft_operation_rra(t_data *data);
void	ft_operation_rrb(t_data *data);
void	ft_operation_rrr(t_data *data);
void	ft_check_order(t_data *data);
int		ft_check_array(char **argv);
void	ft_error(char *line, char **array, t_data *data, int x);
int		*ft_make_int_array(char **numbers, int len);
int		ft_array_size(char **numbers);
int		ft_check_line(char *line);
void	ft_freearray_line(char **array, char *line, t_data *data);

#endif
