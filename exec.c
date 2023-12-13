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
	int status;

	if (argv)
	{
		command = argv[0];

		command_path = location(command);

		pid = fork();

		if (pid == -1)
		{
			perror("Fork failed");
			return (-1);
		}

		if (pid == 0)
		{
			if (execve(command_path, argv, NULL) == -1)
			{
				err("not found", command);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
			{
				return (WEXITSTATUS(status));
			}
			else
			{
				return (-1);
			}
		}
	}
	return (-1);
}

/**
 * exec_with pipe - execute a command with a pipeline
 * @argv: Array of command arguments
 *
 * Return: 0 on success, -1 on failure
 */


int exec_with_pipe(char **argv)
{
	int pipefd[2];
	pid_t pid;
	int status;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		close(pipefd[1]);
		_dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);

		if (execvp(argv[0], argv) == -1)
		{
			perror("execvp");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(pipefd[0]);
		_dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == EXIT_SUCCESS)
			{
				return (0);
			}
			else
			{
				return (-1);
			}

		}
		else
		{
			perror("waitpid");
			return (-1);
		}
	}

	return (0);
}
