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

static char	*check_n_fill(char *src, int len)
{
	char	*lo;
	int	i;

	if (!src || src[len] == '\0')
		return (NULL);
	i = 0;
	lo = (char *) malloc (((ft_strlen(src) - len) + 1) * sizeof(char));
	while (src[len] != '\0')
		lo[i++] = src[len++];
	lo[i] = '\0';
	return (lo);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	static char	*leftover;
	char		*tmp;

	leftover = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (NULL);
	if (ft_strchr(leftover, '\n') != 0)
		line = fill_line(leftover);
	else 
	{
		if (read(fd, buff, BUFFER_SIZE) <= 0)
			return (NULL);
		buff[BUFFER_SIZE] = '\0';
		if (leftover && ft_strchr(buff, '\n'))
			line = fill_line(ft_strjoin(leftover, buff));
		else if (ft_strchr(buff, '\n'))
			line = fill_line(buff);
	}
	if (check_n_fill(leftover, ft_strlen(line)) != 0)
	{
		tmp = check_n_fill(leftover, ft_strlen(line));
		free(leftover);
		leftover = tmp;
	}
	else if (check_n_fill(buff, ft_strlen(line)) != 0)
		leftover = check_n_fill(buff, ft_strlen(line));
	return (line);
}
/*
#include <fcntl.h>

int main()
{
	int	fd;
	fd = open("41_no_nl", O_RDONLY);
	if (fd == -1)
		printf("cannot open file");
	printf("|FD - %d|\n", fd);
	char	*s = get_next_line(fd);
	printf("RESULT1 - %s\n", s);
	//s = get_next_line(fd);
	//printf("RESULT2 - %s\n", s);
	close(fd);
	return (0);
}*/
