/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabir <sabir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:38:16 by sabir             #+#    #+#             */
/*   Updated: 2026/05/17 22:09:26 by sabir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_combn(char *num, int size, int index, int digit)
{
	if (index == size)
	{
		write(1, num, size);
		if (num[0] != '0' + 10 - size)
			write(1, ", ", 2);
		return ;
	}
	while (digit < 10)
	{
		num[index] = '0' + digit;
		print_combn(num, size, index + 1, digit + 1);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	char	num[10];

	if (n < 1 || n > 9)
		return ;
	print_combn(num, n, 0, 0);
}
