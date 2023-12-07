#include "shell.h"

/**
 * exec - main entry point
 * Description: Executes commands
 * @argv: argument array(including command)
 * Return: 0 (Successful) or -1 (Fail)
 */
int exec(char **argv)
{
	char *command = NULL; 
	char *command_path = NULL;
	pid_t pid;

	if (argv)
	{
		/*find the command*/
		command = argv[0];

		/*get the command path before passing to execve*/
		command_path = location(command);

		/*forking a process*/
		pid = fork();
	        
		if (pid == -1)
		{
			perror("Fork failed");
			return (-1);
		}

		
		if (pid == 0)
		{
			/*child process*/
			if (execve(command_path, argv, NULL) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/*Parent process*/
			int exe;
			waitpid(pid, &exe, 0);
			return (0);
		}
	}
	return (-1);
}	
