/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atortora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:10:59 by atortora          #+#    #+#             */
/*   Updated: 2020/11/11 19:11:01 by atortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	index;
	int	result;

	result = 0;
	index = 0;
	while (tab[index])
	{
		if ((*f)(tab[index]) != 0)
		{
			result = 1;
			break ;
		}
		index++;
	}
	return (result);
}
