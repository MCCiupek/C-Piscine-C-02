/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 00:17:53 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/10 11:56:45 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_alphanumeric(char *str)
{
	if (str[0] < '0' || (str[0] > '9' && str[0] < 'A') || 
			(str[0] > 'Z' && str[0] < 'a') || str[0] > 'z')
		return (0);
	return (1);
}

int		ft_str_is_uppercase(char *str)
{
	if (str[0] < 'A' || str[0] > 'Z')
		return (0);
	return (1);
}

int		ft_str_is_lowercase(char *str)
{
	if (str[0] < 'a' || str[0] > 'z')
		return (0);
	return (1);
}

char	*ft_strupcase(char *str)
{
	if (str[0] >= 'a' && str[0] <= 'z')
			str[0] = str[0] - 32;
	return (&str[0]);
}

char	*ft_strlowcase(char *str)
{
	if (str[0] >= 'A' && str[0] <= 'Z')
			str[0] = str[0] + 32;
	return (&str[0]);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0') 
	{
		if (ft_str_is_alphanumeric(&str[i]) == 1)
		{
			if 	(i == 0)
				ft_strupcase(&str[i]);
			else
			{
				if (ft_str_is_alphanumeric(&str[i-1]) == 1)
					ft_strlowcase(&str[i]);
				else
					ft_strupcase(&str[i]);
			}
		}
		i++;
	}
	return (str);
}

int 	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

	printf("%s", ft_strcapitalize(argv[1]));
}
