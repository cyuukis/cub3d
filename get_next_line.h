#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1024
int			get_next_line(int fd, char **line);
int			add_check2(char **choto, char *temp);
char		*ft_strchr(const char *str, int ch);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *str);
int			add_check3(char **choto, char *temp);
#endif
