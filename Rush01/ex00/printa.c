/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:54:39 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/01 18:22:43 by atortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printnbr(int n)
{
	char c;

	c = n + '0';
	write(1, &c, 1);
}

void	print_matrix(int **matrix, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printnbr(matrix[i][j]);
			if (j != size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
