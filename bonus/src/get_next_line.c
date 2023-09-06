/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 19:36:36 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/24 13:41:21 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static int	ft_mallocfail(char *newline, char **line, int x)
{
	if (x == 0)
		free(newline);
	if (x == 1)
		free(line[0]);
	return (-3);
}

static int	ft_realloc_line(char *newline, char **line, int i)
{
	newline = (char *)malloc(i + 1);
	if (newline == NULL)
		return (ft_mallocfail(newline, &line[0], 1));
	i = 0;
	while (line[0][i] != '\0')
	{
		newline[i] = line[0][i];
		i++;
	}
	newline[i] = '\0';
	free(line[0]);
	line[0] = (char *)malloc(i + 2);
	if (line[0] == NULL)
		return (ft_mallocfail(newline, &line[0], 0));
	i = 0;
	while (newline[i] != '\0')
	{
		line[0][i] = newline[i];
		i++;
	}
	free(newline);
	return (1);
}

static int	ft_readline(char buff[1], char *newline, char **line)
{
	int	i;
	int	j;

	i = 0;
	while (line[0][i] != '\0')
		i++;
	j = ft_realloc_line(newline, line, i);
	if (j < 0)
		return (j);
	line[0][i] = buff[0];
	line[0][i + 1] = '\0';
	return (1);
}

int	get_next_line(char **line)
{
	char	buff[1];
	char	*newline;
	int		j;
	int		i;

	newline = NULL;
	line[0] = (char *)malloc(sizeof(char) * 1);
	if (line[0] == NULL)
		return (-2);
	line[0][0] = '\0';
	j = 2;
	while (j != 0)
	{
		j = read(0, buff, 1);
		if (j == -1)
			return (-1);
		if (j == 0)
			return (0);
		if (buff[0] == '\n')
			return (1);
		i = ft_readline(buff, newline, line);
		if (i < 0)
			return (i);
	}
	return (1);
}

void	ft_freearray_line(char **array, char *line, t_data *data)
{
	data->z = 0;
	while (array[data->z] != NULL)
	{
		free(array[data->z]);
		data->z++;
	}
	free(array);
	free(line);
}
