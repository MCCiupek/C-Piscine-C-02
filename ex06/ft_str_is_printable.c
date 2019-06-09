/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:51:56 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/09 23:52:03 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0') 
	{
		if (str[i] < 33)
			return (0);
		i++;
	}
	return (1);
}

int 	main(void)
{
	printf("%d", ft_str_is_printable("aaa\n"));
}
