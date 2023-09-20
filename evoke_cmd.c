#include "shell.h"

/**
 * evoke_command - execute command that are parsed by user
 * @cmd: Users command inputted.
 *
 * Return: Nothing since is void.
 */
void evoke_command(const char *cmd)
{
	pid_t new_pid; /*child process or PID*/
	int i; /*index for user arguments*/

	new_pid = fork();
	if (new_pid == 0)
	{
		char *usr_args[128]; /*array to handle user args added to commands*/
		char *to_ken;

		to_ken = strtok((char *)cmd, " ");
		for (i = 0; to_ken != NULL; i++)
		{
			usr_args[i] = to_ken;
			to_ken = strtok(NULL, " ");
		}
		usr_args[i] = NULL; /*if user argument is NULL terminate*/

		execvp(usr_args[0], usr_args); /*finally execute users argument*/
		print_txt("Error executing user's commands\n");
		exit(EXIT_FAILURE);
	}
	else if (new_pid == -1)
	{
		print_txt("Error encountered during forking\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		/** this section controls the parent process*/
	}

}
