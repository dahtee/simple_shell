#include "shell.h"
/**
 * usr_cmd_placehold - use pointer to get data
 * @cmd: command enter by user.
 * Return: return user command.
 */
char *usr_cmd_placehold(char *cmd)
{
	char *path, *cp_path, *tk_path, *file_path;
	int comlen, dirlen;
	struct stat buff;

	path = getenv("PATH");
	if (path)
	{	cp_path = strdup(path);
		comlen = strlen(cmd);
		tk_path = strtok(cp_path, ":");

		while (tk_path != NULL)
		{	dirlen = strlen(tk_path);
			file_path = malloc(comlen + dirlen + 2);
			strcpy(file_path, tk_path);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			strcat(file_path, "\0");
			if (stat(file_path, &buff) == 0)
			{	free(cp_path);
				return (file_path);
			}
			else
			{
				free(file_path);
				tk_path = strtok(NULL, ":");
			}
		}
		free(cp_path);
		if (stat(cmd, &buff) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}
