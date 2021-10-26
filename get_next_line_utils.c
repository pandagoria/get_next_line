#include "get_next_line.h"

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
	if (!str)
		return (0);
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	if (ft_strlen(src) + 1 < dst_size)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	else if (dst_size != 0)
	{
		ft_memcpy(dst, src, dst_size - 1);
		dst[dst_size - 1] = '\0';
	}
	return (ft_strlen(src));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*str1;

	str = (char *) dst;
	str1 = (char *) src;
	if (!str && !str1)
		return (0);
	while (n--)
	{
		*str++ = *str1++;
	}
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	char	*d_str;
	char	*s_str;
	size_t	dst_len;
	size_t	i;

	d_str = (char *) dst;
	s_str = (char *) src;
	dst_len = ft_strlen(dst);
	i = 0;
	if (dst_size <= dst_len)
		return (ft_strlen(src) + dst_size);
	while (dst_len + i < dst_size - 1 && s_str[i])
	{
		d_str[dst_len + i] = s_str[i];
		i++;
	}
	d_str[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;
	size_t	i;

	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *) malloc ((s1_len + s2_len) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	if (s1)
	{
		ft_strlcpy(new_str, s1, s1_len + 1);
		free(s1);
	}
	while (*s2)
	{
		if (*s2 == '\n')
		{
			new_str[s1_len++] = '\n';
			break ;
		}
		new_str[s1_len++] = *s2++;
	}
	new_str[s1_len] = '\0';
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len && start < s_len)
		return (ft_substr(s, start, ft_strlen(s)));
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && len <= s_len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
