/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:40:39 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/11 20:09:49 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_printable(char *str)
{
	if (str[0] < 32 || str[0] > 127)
		return (0);
	return (1);
}

void	ft_dec2hex(char *str)
{
	char *tab_hex;

	tab_hex = "0123456789abcdef";
	write(1, &tab_hex[str[0] / 16], 1);
	write(1, &tab_hex[str[0] % 16], 1);
}

void	ft_dec2hex_long(void *addr, char *base)
{
	unsigned long long      value;
	char                            c[15];
	int                                     i;

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
	unsigned int j;

	j = 0;
	while (++j <= 16)
	{
		if (j + i - 1 < size)
			ft_dec2hex(&ptr[j + i - 1]);
		else
			write(1, "  ", 2);
		if (j % 2 == 0)
			write(1, " ", 1);
	}
	j = 0;
	while (++j <= 16 && j + i <= size)
	{
		if (ft_str_is_printable(&ptr[j + i - 1]) == 0)
			write(1, ".", 1);
		else
			write(1, &ptr[j + i - 1], 1);
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;
	unsigned long	add;

	ptr = (char *)addr;
	i = 0;
	while (i < size)
	{
		add = (unsigned long)&addr;
		write(1, "00", 2);
		ft_dec2hex_long(addr, "0123456789abcde");
		ft_print_memory_line(ptr, size, i);
		i += 16;
	}
	return (addr);
}

int		main(void)
{
	char	*tab;

	tab = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire "
		"avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	ft_print_memory(tab, 92);
}
