/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabir <sabir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:32:55 by sabir             #+#    #+#             */
/*   Updated: 2026/05/25 15:54:14 by sabir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*strcheck(int size, char **strs, char *sep, char *tab)
{
	int	i;

	i = 0;
	if (!tab)
	{
		return (NULL);
	}
	tab[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(tab, strs[i]);
		if (i < size - 1)
			ft_strcat(tab, sep);
		i++;
	}
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;
	char	*tab;

	if (size <= 0)
	{
		tab = malloc(1);
		tab[0] = '\0';
		return (tab);
	}
	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += ((size - 1) * ft_strlen(sep)) + 1;
	tab = malloc(total_len * sizeof(char));
	return (strcheck(size, strs, sep, tab));
}
