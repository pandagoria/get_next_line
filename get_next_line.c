#include "get_next_line.h"
#include <stdio.h>

static char	*fill_line(char *src)
{
	char	*line;
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
	{
		if (src[len] == '\n')
		{
			len++;
			break ;
		}
		len++;
	}
	line = (char *) malloc ((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = src[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*check_n_fill(char *buff, char *leftover)
{
	char	*lo;
	char	*n_ptr;

	if (leftover)
		free(leftover);
	n_ptr = NULL;
	lo = NULL;
	if (ft_strchr(buff, '\n'))
	{
		n_ptr = ft_strchr(buff, '\n');
		lo = ft_substr(n_ptr + 1, 0, ft_strlen(n_ptr));
	}
	return (lo);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	static char	*leftover;
	int			reader;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (NULL);
	if (ft_strchr(leftover, '\n'))
		line = fill_line(leftover);
	else
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (leftover)
			line = ft_strjoin(line, leftover);
		while (reader)
		{
			buff[BUFFER_SIZE] = '\0';
			line = ft_strjoin(line, buff);
			if (ft_strchr(line, '\n'))
				break ;
			reader = read(fd, buff, BUFFER_SIZE);
		}
	}
	leftover = check_n_fill(buff, leftover);
	return (line);
}
/*
#include <fcntl.h>

int main()
{
	int	fd;
	int	i;
	i = 0;
	fd = open("41_with_nl", O_RDONLY);
	if (fd == -1)
		printf("cannot open file");
	char	*s = get_next_line(fd);
	printf("RES %s\n", s);
	s = get_next_line(fd);
	printf("RES %s\n", s);
	while (i < 40)
	{
		s = get_next_line(fd);
		printf("RESULT - %s\n", s);
		i++;
	}
	close(fd);
	return (0);
}*/
