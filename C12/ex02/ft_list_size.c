/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atortora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:45:32 by atortora          #+#    #+#             */
/*   Updated: 2020/11/12 12:45:42 by atortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int ret;

	ret = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		++ret;
	}
	return (ret);
}
