/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:26:59 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/12 10:27:03 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_read_std(void)
{
	char	c;
	int		file;

	if (!(file = open("./stdinput", O_CREAT | O_WRONLY | O_TRUNC, 0644)))
		return (0);
	while (read(0, &c, 1))
	{
		write(file, &c, 1);
	}
	return (1);
}
