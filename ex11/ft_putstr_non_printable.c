/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:13:59 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/11 23:24:16 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_str_is_printable(char *str)
{
	if (str[0] < 32 || str[0] == 127)
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*tab_hex;

	tab_hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_str_is_printable(&str[i]) == 0)
		{
			ft_putchar(92);
			ft_putchar(tab_hex[str[i] / 16]);
			ft_putchar(tab_hex[str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
