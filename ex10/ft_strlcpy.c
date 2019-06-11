/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:17:28 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/11 23:23:19 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (src[i] == '\0')
		{
			dest[i] = '\0';
			break ;
		}
		else
		{
			if (i == size - 1)
			{
				dest[i] = '\0';
				break ;
			}
			else
				dest[i] = src[i];
		}
		i++;
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
