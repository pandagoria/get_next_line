#include "get_next_line.h"

static char	*read_fd(fd)
{
	char	*buff;
	size_t	reader;

	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	reader = read(fd, buff, BUFFER_SIZE);
	if (reader < 0)
		return (NULL);
	buff[len(buff)] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*line;
	static char 	*leftover;
	size_t	i;

	if (fd < 0)
		return (NULL);
	if (ft_strchr(leftover, '\n'))
		
	buff = read_fd(fd);
	while (*buff != '\n' || *buff != '\0')
		*line++ = *buff++;
	if (*buff == '\n')
		*line = '\n';
	else if (*buff == '\0')
	{
		*line = '\0';
		free(buff);
		free(leftover);
		return (line);
	}
	buff++;
	leftover = ft_strdup(buff);
	free(buff);
	return (line);
}

