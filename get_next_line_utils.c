#include "get_next_line.c"

size_t	len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dup;

	i = ft_strlen(s1) + 1;
	dup = (char *) malloc(i * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s1, i);
	return (dup);
}

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*pntr;

	i = 0;
	pntr = (char *) str;
	while (pntr[i])
	{
		if (pntr[i] == (char) ch)
			return (&pntr[i]);
		i++;
	}
	if (ch == '\0')
		return (&pntr[i]);
	return (0);
}
