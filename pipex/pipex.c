#include "pipex.h"

void	free_mas(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
}

int	error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

void	free_par(t_par *control)
{
	close(control->fd[0]);
	close(control->fd[1]);
	waitpid(control->pid1, NULL, 0);
	waitpid(control->pid1, NULL, 0);
	free_mas(control->paths);
	close(control->infile);
	close(control->outfile);
}

char	*f_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		++envp;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_par	control;

	if (argc != 5)
		exit(error("Invalid number of arguments.\n"));
	control.infile = open(argv[1], O_RDONLY);
	if (control.infile < 0)
		exit(error("Infile error\n"));
	control.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (control.outfile < 0)
		exit(error("Outfile error\n"));
	if (pipe(control.fd) == -1)
		exit(error("Pipe error\n"));
	control.path = f_path(envp);
	control.paths = ft_split(control.path, ':');
	control.pid1 = fork();
	if (control.pid1 == 0)
		fst_chld(&control, argv, envp);
	control.pid2 = fork();
	if (control.pid2 == 0)
		scnd_chld(&control, argv, envp);
	free_par(&control);
	exit(0);
}
