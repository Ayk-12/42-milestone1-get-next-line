/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchelde <atchelde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:12:15 by atchelde          #+#    #+#             */
/*   Updated: 2026/01/13 15:14:11 by atchelde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rt_new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	rt_new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rt_new)
		return (NULL);
	while (s1[i])
	{
		rt_new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		rt_new[i] = s2[j];
		i++;
		j++;
	}
	rt_new[i] = '\0';
	return (rt_new);
}

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		str++;
		length++;
	}
	return (length);
}

int	ft_index(const char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		i++;
		str++;
	}
	return (-1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*temp;
	size_t			i;

	if (size == 0 || nmemb == 0)
		return (malloc(1));
	if (nmemb >= __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (! ptr)
		return (NULL);
	temp = (unsigned char *)ptr;
	i = 0;
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return (ptr);
}
