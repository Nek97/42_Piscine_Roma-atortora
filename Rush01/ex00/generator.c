/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:05:01 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/01 18:21:53 by atortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorial(int n)
{
	if (n == 0)
		return (1);
	return (n * ft_factorial(n - 1));
}

void	wrong_n(int *n, int *j)
{
	*n += 1;
	*j = -1;
}

int		gen_n(int **matrix, int row, int col, int range)
{
	int n;
	int j;
	int i;
	int fact;
	int temp;

	fact = ft_factorial(range - col - 1);
	n = 1;
	j = -1;
	while (++j < col)
		if (matrix[row][j] == n)
			wrong_n(&n, &j);
		else
		{
			i = -1;
			temp = row - fact;
			while (temp >= 0 && ++i < (range - col - 1) && j != -1)
			{
				if (matrix[temp][col] == n)
					wrong_n(&n, &j);
				temp -= fact;
			}
		}
	return (n);
}

int		call_gen(int **matrix, int row, int col, int range)
{
	int fact;

	fact = ft_factorial(range - col - 1);
	if (row == 0)
		return (col + 1);
	if (col == 0 && row >= fact)
		return (matrix[row - fact][col] + 1);
	return (gen_n(matrix, row, col, range));
}

int		gen_rec(int **matrix, int row, int col, int range)
{
	int i;
	int fact;

	if (col == (range - 1))
	{
		matrix[row][col] = call_gen(matrix, row, col, range);
		return (row + 1);
	}
	else
	{
		i = 0;
		fact = ft_factorial(range);
		while (i < fact)
		{
			matrix[row][col] = call_gen(matrix, row, col, range);
			if (row != gen_rec(matrix, row, col + 1, range))
				if (col != 0)
					return (row + 1);
			row++;
			i++;
		}
		return (row);
	}
}
