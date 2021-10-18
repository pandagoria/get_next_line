#include "get_next_line.h"

char	*read_fd(fd)
{
	char	*buff;
	size_t	reader;

	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	reader = read(fd, buff, BUFFER_SIZE);
	if (reader < 0)
		return (NULL);
	buff[i] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*line;
	size_t	i;

	if (fd < 0)
		return (NULL);
	buff = read_fd(fd);
	i = 0;
	while (buff[i] != '\n' || buf[i] != '\0')
	{
		line[i] = buff[i];
	}
	if (buff[i] == '\0')
		line[i] = '\0';
	else if (buff[i] == '\n')
		line[i] = '\n';
	return (line);
}
