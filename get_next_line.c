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

static char	*check_n_fill(char *buff, char *leftover, char *line)
{
	char	*lo;
	int	len;

	len = 0;
	lo = NULL;
	if (line)
		len = ft_strlen(line);
	if (!line && buff && leftover)
		lo = ft_strjoin(leftover, buff);
	else if (!line && !leftover && buff)
		lo = ft_strdup(buff);
	return (lo);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	static char	*leftover;

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
	leftover = check_n_fill(buff, leftover, line);
	printf("%s\n", leftover);
	return (line);
}

#include <fcntl.h>

int main()
{
	int	fd;
	int	i;
	i = 0;
	fd = open("41_with_nl", O_RDONLY);
	if (fd == -1)
		printf("cannot open file");
	printf("|FD - %d|\n", fd);
	char	*s = get_next_line(fd);
	while (i < 40)
	{
		s = get_next_line(fd);
		printf("RESULT - %s\n", s);
		i++;
	}
	close(fd);
	return (0);
}
