#include "get_next_line.h"
#include <stdio.h>

static char	*fill_lo(char *buff, int len)
{
	char	*lo;
	int		i;

	lo = (char *) malloc((ft_strlen(buff) - len + 1) * sizeof(char));
	if (!lo)
		return (NULL);
	i = 0;
	while (buff[len] != '\0')
	{
		lo[i] = buff[len];
		i++;
		len++;
		printf("LO %c\n", lo[i]);
	}
	lo[i] = '\0';
	//printf("LO - %s\n", lo);
	return (lo);
}

static char	*new_line(char *buff, int i)
{
	char	line[];

	
}

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
			while (*leftover != '\n')
				*line++ = *leftover++;
			printf("%s\n", line);
			return ((char *)line);
		}
	}
	if (leftover != 0 && buff != 0)
	{
		temp = ft_strjoin(leftover, buff);
		buff = temp;
	}
	i = 0;
	line = (char *) buff;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	printf("line = %s", line);
	if (buff[++i] != '\0')
		leftover = fill_lo(buff, i);
	line = new_line(buff, i);
	free(buff);
	if (reader == 0)
	{
		printf("Ebat chto ty tut delaesh blyat'");
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
