/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 00:17:53 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/12 11:15:44 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alphanumeric(char *str)
{
	if (str[0] < '0' || (str[0] > '9' && str[0] < 'A') || (str[0] > 'Z' &&
				str[0] < 'a') || str[0] > 'z')
		return (0);
	return (1);
}

int		ft_str_is_uppercase(char *str)
{
	if (str[0] < 'A' || str[0] > 'Z')
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
			if (i == 0)
				ft_strupcase(&str[i]);
			else
			{
				if (ft_str_is_alphanumeric(&str[i - 1]) == 1)
				{
					if (str[i] >= 'A' && str[i] <= 'Z')
						str[i] = str[i] + 32;
				}
				else
					ft_strupcase(&str[i]);
			}
		}
		i++;
	}
	return (str);
}
