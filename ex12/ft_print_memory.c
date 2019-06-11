/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:40:39 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/11 13:43:45 by mciupek          ###   ########.fr       */
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
	if (str[0] < 32 || str[0] > 127)
		return (0);
	return (1);
}

void	ft_dec2hex(char *str)
{
	char *tab_hex;

	tab_hex = "0123456789abcdef";
	ft_putchar(tab_hex[str[0] / 16]);
	ft_putchar(tab_hex[str[0] % 16]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	ptr = (char *)addr;
	i = 0;
	j = 0;

	if (size == 0)
		return (0); 
	
	while (i < size)
	{
		printf("%p\n", addr);
		while (j < size || j <= 16)
		{
			if (j < size)
				ft_dec2hex(&ptr[j]);
			if (j > size)
				write(1, "  ", 2);
			if ((j + 1) % 2 == 0)
				ft_putchar(' ');
			j++;
		}
		j = 0;
		while (j < size)
		{
			if (ft_str_is_printable(&ptr[j]) == 0)
				ft_putchar('.');
			else
				ft_putchar(ptr[j]);
			j++;
		}
		ft_putchar('\n');
	i = i + 16;
	}

	return (addr);
}

int		main(void)
{
	char	tab[] = {'0',':','2','J','j','\n','6','\t','^','M', 'q', '2', '?',
		'*', 't', '\v', 'r'};
	printf("%p\n", tab);
	ft_print_memory(tab, 17);
}

