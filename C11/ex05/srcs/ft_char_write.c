/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atortora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:14:17 by atortora          #+#    #+#             */
/*   Updated: 2020/11/11 19:14:21 by atortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_io.h"

void	ft_char_write_to(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_char_write(char c)
{
	ft_char_write_to(OUT, c);
}
