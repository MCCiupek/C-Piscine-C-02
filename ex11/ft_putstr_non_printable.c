/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:13:59 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/10 19:31:26 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_str_is_printable(char *str)
{
	if (str[0] < 33 && str[0] != ' ')
		return (0);
	return (1);
}

/*char ft_dec2hex(int nb)
{
	char	tab_hex[16] ;
	int		p;
	int		pow;
	int 	n;
	char 	str[2];
	int		i;

	tab_hex = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
		'b', 'c', 'd', 'e', 'f'};
	
	while (nb < 16)
	{
		p = 0;
		pow = 1;
		n = nb;
		while (n / 16 != 0)
		{
			n = n / 16;
			p++;
		}
		while ((--p + 1) > 0)
			pow = pow * 16;
		str[i] = tab_hex[nb / pow];
		nb = nb % pow;
		i++;
	}
	return (str);
}*/

void	ft_putstr_non_printable(char *str)
{
	int i;
	char *tab_hex;

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

int  main()
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}
