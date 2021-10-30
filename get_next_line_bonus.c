/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:50:53 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/30 14:50:58 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	check_n_eof(char *buff)
{
	char	*n_ptr;
	int		i;

	n_ptr = ft_strchr(buff, '\n');
	i = 0;
	if (!n_ptr || (n_ptr + 1) == '\0')
	{
		while (buff[i] != '\0')
			buff[i++] = 0;
		return (1);
	}
	return (0);
}

static void	copy_buff_nl(char *buff)
{
	char	new_buff[BUFFER_SIZE + 1];
	int		i;
	int		j;

	if (check_n_eof(buff) == 1)
		return ;
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			break ;
		i++;
	}
	j = 0;
	while (buff[i] != '\0')
		new_buff[j++] = buff[++i];
	new_buff[j] = '\0';
	i = 0;
	while (new_buff[i] != '\0')
	{
		buff[i] = new_buff[i];
		i++;
	}
	buff[i] = '\0';
}

static char	*fill_line(char *s1, char *s2)
{
	size_t	s1_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	new_str = (char *) malloc ((s1_len + ft_strlen(s2) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	if (s1)
	{
		new_str = ft_strlcpy(new_str, s1, s1_len + 1);
		free(s1);
	}
	while (*s2)
	{
		if (*s2 == '\n')
		{
			new_str[s1_len++] = *s2;
			break ;
		}
		new_str[s1_len++] = *s2++;
	}
	new_str[s1_len] = '\0';
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char		buff[10240][BUFFER_SIZE + 1];
	char			*line;
	int				reader;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buff[fd], 0) < 0)
		return (NULL);
	if (buff[fd][0] != '\0')
	{
		line = fill_line(line, buff[fd]);
		copy_buff_nl(buff[fd]);
	}
	if (ft_strchr(line, '\n'))
		return (line);
	reader = read(fd, buff[fd], BUFFER_SIZE);
	while (reader > 0)
	{
		buff[fd][reader] = '\0';
		line = fill_line(line, buff[fd]);
		copy_buff_nl(buff[fd]);
		if (ft_strchr(line, '\n'))
			break ;
		reader = read(fd, buff[fd], BUFFER_SIZE);
	}
	return (line);
}
