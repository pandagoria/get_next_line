#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buff;
	char	*line;
	static char	*leftover;
	char	*temp;
	int	reader;
	int	i;

	if (fd < 0)
		return (NULL);
	if (!leftover)
	{
		buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader < 0)
			return (NULL);
		buff[ft_strlen(buff)] = '\0';
		printf("%d, length - %zu |%s|\n", reader, ft_strlen(buff), buff);
		if (leftover != 0)
		{
			temp = buff;
			free(buff);
			buff = ft_strjoin(leftover, temp);
			free(leftover);
		}
		line = (char *) buff;
		i = 0;
		while (*buff != '\n' && *buff != '\0')
		{
			printf("%c\n", *buff);
			*line++ = *buff++;
		}
		if (*buff == '\n')
		{
			*line = '\n';
			leftover = ft_strdup(buff);
			free(buff);
		}
		else if (reader == 0)
		{
			printf("Ebat chto ty tut delaesh blyat'");
			*line = '\0';
			free(buff);
			free(leftover);
		}
	}
	
	return (line);
}

#include <fcntl.h>

int main()
{
	int	fd;
	fd = open("n.txt", O_RDONLY);
	if (fd == -1)
		printf("cannot open file");
	printf("fd - %d\n", fd);
	char	*s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	close(fd);
	return (0);
}
