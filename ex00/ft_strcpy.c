/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 21:03:47 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/10 15:08:56 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;
	
	i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

int		main(void)
{
	int n = 2;
	char dest[n];
	char *src;
	
	src = "Hello";
	printf("ft_strcpy = %s\n", ft_strcpy(dest, src));
	printf("strcpy = %s", strcpy(dest, src));
}
