/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:07:08 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/01 18:19:32 by atortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_inputs(char *str, int **inputs, int size)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			inputs[i][j] = str[2 * ((i * size) + j)] - '0';
			if (i % 2 == 1)
			{
				if ((inputs[i][j] + inputs[i - 1][j]) > size + 1
						|| (inputs[i][j] + inputs[i - 1][j]) < 3)
					return (0);
			}
			if (inputs[i][j] > size || inputs[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_char(char c, int *j, int *is_valid)
{
	if (c < '0' || c > '9')
	{
		if (c == ' ')
			if (*is_valid == 0)
				*is_valid = 1;
			else
				return (0);
		else
			return (0);
	}
	else
	{
		*j = *j + 1;
		*is_valid = 0;
	}
	return (1);
}

int		check_args(char *str)
{
	int i;
	int is_valid;
	int j;

	j = 0;
	i = 0;
	is_valid = 0;
	while (*(str + i) != '\0')
		if (check_char(*(str + i), &j, &is_valid))
			i++;
		else
			return (0);
	i = 1;
	while (i * 4 <= j)
	{
		if ((i * 4) == j)
			return (i);
		i++;
	}
	return (0);
}

void	error(int n)
{
	char c;

	c = n + '0';
	write(1, &c, 1);
	write(1, "Error\n", 6);
}
