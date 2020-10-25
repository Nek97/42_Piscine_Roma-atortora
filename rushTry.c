/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushTry.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atortora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 11:06:35 by atortora          #+#    #+#             */
/*   Updated: 2020/10/25 11:06:43 by atortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rush(int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < y && x > 0 && (j = -1))
	{
		while (++j < x)
			if ((j == 0 || j == x - 1) && (i == 0 || i == y - 1))
				ft_putchar('o');
			else if (j == 0 || j == x - 1)
				ft_putchar('|');
			else if (i == 0 || i == y - 1)
				ft_putchar('-');
			else
				ft_putchar(' ');
		ft_putchar('\n');
	}
}

int		main(void)
{
	rush(1, 1);
	rush(5, 3);
	rush(3, 5);
	rush(1, 5);
	rush(5, 1);
	rush(5, 5);
	rush(123, 42);
}
