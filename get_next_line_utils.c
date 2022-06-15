/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:20:23 by ebeiline          #+#    #+#             */
/*   Updated: 2021/06/20 12:33:06 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_isnewl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tdest;
	char	*tsrc;
	size_t	i;

	i = 0;
	tdest = (char *)dest;
	tsrc = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return ((void *)dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tdest;
	char	*tsrc;

	tdest = (char *)dest;
	tsrc = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	if (tsrc < tdest)
	{
		while (n)
		{
			tdest[n - 1] = tsrc[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*rtn;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	stot_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * stot_len);
	if (!rtn)
		return (0);
	ft_memmove(rtn, s1, s1_len);
	ft_memmove(rtn + s1_len, s2, s2_len);
	rtn[stot_len - 1] = '\0';
	free((char *)s1);
	return (rtn);
}
