/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:31:19 by mlopez-i          #+#    #+#             */
/*   Updated: 2023/09/26 21:12:33 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Frees the static variable
char	*ft_free(char **stat)
{
	if (*stat)
		free(*stat);
	*stat = NULL;
	return (NULL);
}

// Fills the static variable with read() until it find a new line or until there
// are no more lines to get (EOF)
char	*ft_fill_static(char *stat, int fd)
{
	int		rb;
	char	*buf;

	rb = 42;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (ft_free(&stat));
	buf[0] = '\0';
	while (!ft_strchr(stat, '\n') && rb > 0)
	{
		rb = read(fd, buf, BUFFER_SIZE);
		if (rb > 0)
		{
			buf[rb] = '\0';
			stat = ft_strjoin(stat, buf);
			if (!stat)
				return (ft_free(&buf));
		}
	}
	free(buf);
	if (rb == -1)
		return (ft_free(&stat));
	return (stat);
}

// Cleans the static variable leaving, only, the characters not returned
// (removes the returned line)
char	*ft_clean_static(char *stat, size_t linesize)
{
	char	*newstat;

	if (!stat[linesize])
		return (ft_free(&stat));
	newstat = ft_substr(stat, linesize, ft_strlen(stat) - linesize);
	ft_free(&stat);
	if (!newstat)
		return (NULL);
	return (newstat);
}

// Gets the new line to return by get_next_line
char	*ft_linetoret(char **stat)
{
	char	*line;
	size_t	linesize;

	line = NULL;
	if (ft_strlen(*stat) == 0)
		return (ft_free(stat));
	if (ft_strchr(*stat, '\n'))
	{
		linesize = ft_strlen(*stat) - ft_strlen(ft_strchr(*stat, '\n')) + 1;
		line = ft_substr(*stat, 0, linesize);
		if (!line)
			return (ft_free(stat));
		*stat = ft_clean_static(*stat, linesize);
	}
	else
	{
		line = *stat;
		*stat = NULL;
	}
	return (line);
}

// Main function to get_next_line
char	*get_next_line(int fd)
{
	static char	*stat = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stat)
	{
		stat = malloc(1);
		if (!stat)
			return (NULL);
		stat[0] = '\0';
	}
	stat = ft_fill_static(stat, fd);
	if (!stat)
		return (NULL);
	return (ft_linetoret(&stat));
}
