/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlopez-i <mlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:33:20 by mlopez-i          #+#    #+#             */
/*   Updated: 2023/08/17 17:29:11 by mlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

// Get next line
char	*ft_free(char **stat);
char	*ft_fill_static(char *stat, int fd);
char	*ft_clean_static(char *stat, size_t reslen);
char	*ft_linetoret(char **stat);
char	*get_next_line(int fd);

// Get next line utils
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *st, char *buf);
#endif