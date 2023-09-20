#include "shell.h"

/**
 * evoke_user_command - execute command that are parsed by user
 * @ur_args: Users command inputted.
 *
 * Return: Nothing since is void.
 */
void evoke_user_command(char **ur_args)
{
	char *cmd = NULL;
	char *cmd_stream;

	if (ur_args)
	{
		/* get the command */
		cmd = ur_args[0];
		cmd_stream = usr_cmd_placehold(cmd);

		/* execute the command with execve */
		if (execve(cmd_stream, ur_args, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
