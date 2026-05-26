/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabir <sabir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:23:27 by sabir             #+#    #+#             */
/*   Updated: 2026/05/25 19:52:13 by sabir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	aff_a(char *str)
{
	int	i;

	i = 0;
	if (!str[0] || !str[1])
	{
		write(1, "a\n", 2);
	}
	while (str[i] != '\0')
	{
		if (str[i] == 'a')
		{
			write(1, "a\n", 2);
			return ;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	char	*str;

	str = "sabir";
	aff_a(str);
	return (0);
}
