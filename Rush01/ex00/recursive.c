/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:06:39 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/01 18:22:10 by atortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorial(int n);

void	excludecombs(int **combs, int i, int row, int size)
{
	int n;
	int k;

	n = 0;
	while (n < size)
	{
		k = 0;
		while (k < ft_factorial(size))
		{
			if (combs[k][size + 2] == -1)
			{
				if (combs[k][n] == combs[i][n])
				{
					combs[k][size + 2] = row;
				}
			}
			k++;
		}
		n++;
	}
}

void	clearcombs(int **combs, int row, int size)
{
	int n;

	n = 0;
	while (n < ft_factorial(size))
	{
		if (combs[n][size + 2] == row)
		{
			combs[n][size + 2] = -1;
		}
		n++;
	}
}

int		recursive(int ***very_big_pp, int riga, int size)
{
	int i;
	int j;

	i = 0;
	if (riga == size)
		return (1);
	while (i < ft_factorial(size))
	{
		while (i < ft_factorial(size) - 1 && very_big_pp[0][i][size + 2] != -1)
			i++;
		if (very_big_pp[0][i][size] == very_big_pp[1][2][riga] &&
				very_big_pp[0][i][size + 1] == very_big_pp[1][3][riga])
		{
			j = -1;
			while (++j < size)
				very_big_pp[2][riga][j] = very_big_pp[0][i][j];
			excludecombs(very_big_pp[0], i, riga, size);
			if (recursive(very_big_pp, riga + 1, size))
				return (1);
		}
		clearcombs(very_big_pp[0], riga, size);
		i++;
	}
	return (0);
}
