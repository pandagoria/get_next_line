#include "get_next_line.h"
#include <stdio.h>

/*static char	*new_lo(char *s)
{
	char	*temp;

	temp = s;
	while(s++)
	free(s);
}*/

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
		printf("READER - %d, length - %zu |%s|\n", reader, ft_strlen(buff), buff);
	}
	if (leftover)
	{
		if (ft_strchr(leftover, '\n'))
		{
			line = (char *) leftover;
			while (*leftover != '\n')
			{
				printf("%c\n", *line);
				*line++ = *leftover++;
			}
			*line = '\n';
			if (*leftover++)
				leftover = "puk";
			return (line);
		}
	}
	if (leftover != 0 && buff != 0)
	{
		temp = buff;
		free(buff);
		buff = ft_strjoin(leftover, temp);
		free(leftover);
	}
	i = 0;
	line = buff;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		i++;
	}
	printf("%s", line);
	if (buff[i] == '\n')
	{
		line[i] = '\n';
	}
	if (reader == 0)
	{
		printf("Ebat chto ty tut delaesh blyat'");
		*line = '\0';
		free(buff);
		free(leftover);
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
	printf("|FD - %d|\n", fd);
	char	*s = get_next_line(fd);
	printf("RESULT1 - %s\n", s);
	s = get_next_line(fd);
	printf("RESULT2 - %s", s);
	close(fd);
	return (0);
}
