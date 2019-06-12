/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:40:39 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/12 14:13:00 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_printable(unsigned char *str)
{
	if (str[0] < 32 || str[0] == 127)
		return (0);
	return (1);
}

void	ft_dec2hex(unsigned char *str)
{
	char *tab_hex;

	tab_hex = "0123456789abcdef";
	write(1, &tab_hex[str[0] / 16], 1);
	write(1, &tab_hex[str[0] % 16], 1);
}

void	ft_dec2hex_long(void *addr, char *base)
{
	unsigned long long	value;
	char				c[15];
	int					i;

	i = 0;
	value = (unsigned long long)addr;
	while (i < 15)
	{
		c[14 - i] = base[value % 16];
		value /= 16;
		i++;
	}
	write(1, c, 15);
	write(1, ": ", 2);
}

void	ft_print_memory_line(char *ptr, unsigned int size, unsigned int i)
{
	unsigned int	j;
	unsigned char	p;

	j = 0;
	while (++j <= 16)
	{
		p = (unsigned char)ptr[j + i - 1];
		if (j + i - 1 < size)
			ft_dec2hex(&p);
		else
			write(1, "  ", 2);
		if (j % 2 == 0)
			write(1, " ", 1);
	}
	j = 0;
	while (++j <= 16 && j + i <= size)
	{
		p = (unsigned char)ptr[j + i - 1];
		if (ft_str_is_printable(&p) == 0)
			write(1, ".", 1);
		else
			write(1, &p, 1);
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*ptr;

	ptr = (char *)addr;
	i = 0;
	while (i < size)
	{
		ft_dec2hex_long(&addr[i], "0123456789abcde");
		ft_print_memory_line(ptr, size, i);
		i += 16;
	}
	return (addr);
}
