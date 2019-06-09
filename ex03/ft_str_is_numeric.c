/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:18:50 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/09 23:30:34 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_numeric(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0') 
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int 	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	
	printf("%d", ft_str_is_numeric(argv[1]));
}
