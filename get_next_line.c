#include "get_next_line.h"
#include <stdio.h>

static void	copy_buff(char *buff)
{
	int		i;
	int		j;
	char	new_buff[BUFFER_SIZE + 1];
	char	*n_ptr;

	n_ptr = ft_strchr(buff, '\n');
	i = 0;
	if (!n_ptr || (n_ptr + 1) == '\0')
	{
		while (buff[i] != '\0')
			buff[i++] = 0;
		return ;
	}
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

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1];
	char			*line;
	int				reader;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (NULL);
	if (ft_strchr(buff, '\n'))
	{
		line = ft_strjoin(line, buff);
		copy_buff(buff);
	}
	else
	{
		if (buff[0] != '\0')
		{
			line = ft_strjoin(line, buff);
			copy_buff(buff);
		}
		reader = read(fd, buff, BUFFER_SIZE);
		while (reader > 0)
		{
			buff[BUFFER_SIZE] = '\0';
			line = ft_strjoin(line, buff);
			copy_buff(buff);
			if (ft_strchr(line, '\n'))
				break ;
			reader = read(fd, buff, BUFFER_SIZE);
		}
		if (reader == 0)
			buff[0] = 0;
	}
	return (line);
}
/*
#include <fcntl.h>

int main()
{
	int	fd;
	int	i;
	i = 0;
	fd = open("multiple_line_with_nl", O_RDONLY);
	if (fd == -1)
		printf("cannot open file");
	while (i <= 6)
	{
		char *s = get_next_line(fd);
		printf("RESULT - %s\n", s);
		i++;
	}
	close(fd);
	return (0);
}
*/
