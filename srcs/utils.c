#include "../includes/pipex.h"

/* This function will join s1 and s2, returning the contatenation of both. */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		size;
	int		i;

	if (!s1)
		return (NULL);
	i = -1;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(size * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	i = -1;
	while (s2[++i])
		dst[i + ft_strlen(s1)] = s2[i];
	dst[i + ft_strlen(s1)] = '\0';
	return (dst);
}

/* Function that will read input from the terminal and return line. */
int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}