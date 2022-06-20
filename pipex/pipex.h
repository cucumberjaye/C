#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/uio.h>

typedef struct s_par
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*cmd1;
	char	*cmd2;
	char	**strs1;
	char	**strs2;
	char	*path;
	char	**paths;

}		t_par;

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*sch_cmd(char **paths, char *cmd);
size_t	ft_strlen(const char *str);
void	fst_chld(t_par *control, char **argv, char **envp);
void	scnd_chld(t_par *control, char **argv, char **envp);
int		error(char *str);
void	free_mas(char **str);

#endif
