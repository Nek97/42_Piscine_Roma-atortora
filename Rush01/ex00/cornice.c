/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cornice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:06:07 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/01 16:40:20 by cguiducc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		new_max(int *reads, int **matrix, int row, int col)
{
	*reads = *reads + 1;
	return (matrix[row][col]);
}

void	generate_borders(int **matrix, int range, int rows)
{
	int i;
	int reads;
	int max;
	int j;

	i = -1;
	while (++i < rows)
	{
		j = 0;
		reads = 1;
		max = matrix[i][0];
		while (++j < range)
			if (matrix[i][j] > max)
				max = new_max(&reads, matrix, i, j);
		matrix[i][range] = reads;
		reads = 1;
		max = matrix[i][range - 1];
		while (--j >= 0)
			if (matrix[i][j] > max)
				max = new_max(&reads, matrix, i, j);
		matrix[i][range + 1] = reads;
		matrix[i][range + 2] = -1;
	}
}
