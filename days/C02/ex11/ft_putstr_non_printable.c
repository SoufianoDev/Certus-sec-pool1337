/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabir <sabir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:21:54 by sabir             #+#    #+#             */
/*   Updated: 2026/05/16 20:39:36 by sabir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hex;
	int		i;
	int		a;
	int		b;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (str[i] < 32)
		{
			a = (str[i] / 16);
			b = (str[i] % 16);
			write(1, "\\", 1);
			write(1, &hex[a], 1);
			write(1, &hex[b], 1);
		}
		else if (str[i] >= 32)
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
