/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atortora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:40:06 by atortora          #+#    #+#             */
/*   Updated: 2020/11/12 12:40:10 by atortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *ret;

	ret = (t_list*)malloc(sizeof(t_list));
	ret->data = data;
	ret->next = 0;
	return (ret);
}
