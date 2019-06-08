/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 00:17:31 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/09 00:32:51 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;
			
	i = 0;

	while (i <= n)
	{
		if (src[i] == '\0')
			dest[i] = '\0';	
		else
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}