/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:07:10 by acilione          #+#    #+#             */
/*   Updated: 2020/11/12 09:10:57 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_valid_chars(char a, char b, char c)
{
	return
	(
		ft_three_diff_chars(a, b, c) &&
		ft_char_is_printable(a) &&
		ft_char_is_printable(b) &&
		ft_char_is_printable(c));
}
