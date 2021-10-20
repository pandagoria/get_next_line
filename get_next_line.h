#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	len(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int ch);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
