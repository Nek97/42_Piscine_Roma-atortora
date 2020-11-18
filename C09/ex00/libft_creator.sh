# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atortora <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 15:58:49 by atortora          #+#    #+#              #
#    Updated: 2020/11/11 15:58:56 by atortora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rm -f libft.a
find . -name "*.c" -type f -maxdepth 1 -exec gcc -Wall -Werror -Wextra -c {} \;
ar -rcs libft.a *.o
find . -name "*.o" -type f -maxdepth 1 -delete
