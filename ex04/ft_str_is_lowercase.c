/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:31:04 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/09 23:33:52 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_lowercase(char *str)
{
	int i;
		
	i = 0;
	while (str[i] != '\0') 
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}

int 	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
			
	printf("%d", ft_str_is_lowercase(argv[1]));
}

