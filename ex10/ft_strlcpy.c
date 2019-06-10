/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:17:28 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/10 15:13:33 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;

	while (i < size)
	{
		if (src[i] == '\0')
		{
			dest[i] = '\0';
			break;
		}
		else
			dest[i] = src[i];
		i++;
	}
	while (src[i] != '\0')
		i++;
	return i;
}

int 	main(void)
{
	unsigned int size = 3; 
	char dest[size];
	char *src;
	
	src = "Hello";
	printf("ft_strlcpy = %d\n", ft_strlcpy(dest, src, size));
	printf("strlcpy = %lu", strlcpy(dest, src, size));
}
