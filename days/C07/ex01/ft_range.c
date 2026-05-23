/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabir <sabir@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 23:21:54 by sabir             #+#    #+#             */
/*   Updated: 2026/05/21 00:44:49 by sabir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int min, int max)
{
	int	size;
	int	*arr;
	int	i;

	size = max - min;
	if (size <= 0)
	{
		return (NULL);
	}
	arr = malloc(size * sizeof(int));
	if (!arr)
	{
		return (NULL);
	}
	i = 0;
	while (i <= size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
