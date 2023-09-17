#include "shell.h"
/**
 * evoke_command - execute command that are parsed by user
 * @cmd: Users command inputted.
 *
 * Return: Nothing since is void.
 */
void evoke_command(const char *cmd)
{
	pid_t new_pid;

	new_pid = fork();
	if (new_pid == 0)
	{
		execlp(cmd, cmd, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else if (new_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		/** this section controls the parent process*/
	}

}
