/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:31:33 by mlopez-i          #+#    #+#             */
/*   Updated: 2023/09/26 21:10:34 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Returns the length of string str
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Finds the first occurrence of char c
char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

//Returns a substring starting from start and with length len
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			slen;
	char			*res;

	slen = ft_strlen(s);
	if (start >= slen)
		return ("");
	if (start + len > slen)
		len = slen - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// Concatenates s1 and s2 in a new string
char	*ft_strjoin(char *st, char *buf)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc(sizeof(char) * (ft_strlen(st) + ft_strlen(buf) + 1));
	if (!res || !st || !buf)
		return (ft_free(&st));
	i = 0;
	j = 0;
	while (st[i])
	{
		res[i] = st[i];
		i++;
	}
	while (buf[j])
	{
		res[i] = buf[j];
		i++;
		j++;
	}
	res[i] = '\0';
	if (st)
		free(st);
	st = NULL;
	return (res);
}
