#include "pipex.h"

char	*sch_cmd(char **paths, char *cmd)
{
	char	*sch_cmd;

	while (paths)
	{	
		sch_cmd = ft_strjoin(ft_strjoin(*paths, "/"), cmd);
		if (access(sch_cmd, 0) == 0)
			return (sch_cmd);
		free(sch_cmd);
		++paths;
	}
	return (NULL);
}

void	fst_chld(t_par *control, char **argv, char **envp)
{
	dup2(control->fd[1], 1);
	close(control->fd[0]);
	dup2(control->infile, 0);
	control->strs1 = ft_split(argv[2], ' ');
	control->cmd1 = sch_cmd(control->paths, control->strs1[0]);
	if (!control->cmd1)
	{
		free_mas(control->strs1);
		error("Cmd error\n");
		exit(1);
	}
	execve(control->cmd1, control->strs1, envp);
}

void	scnd_chld(t_par *control, char **argv, char **envp)
{
	dup2(control->fd[0], 0);
	close(control->fd[1]);
	dup2(control->outfile, 1);
	control->strs2 = ft_split(argv[3], ' ');
	control->cmd2 = sch_cmd(control->paths, control->strs2[0]);
	if (!control->cmd2)
	{
		free_mas(control->strs2);
		error("Cmd error\n");
		exit(1);
	}
	execve(control->cmd2, control->strs2, envp);
}
