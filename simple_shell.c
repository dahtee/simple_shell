#include "shell.h"
/**
 * main - entry point of code
 * @ac: number of commands
 * @argv: Lenght of commands.
 * Return: return o for successful
 */
int main(int ac, char **argv)
{	char *usr_cmd = NULL, *cp_urs_cmd = NULL, *to_ken;
	size_t usr_cmd_size = 0;
	ssize_t read_csize;
	const char *delim = " \n";
	int tokenizer = 0, i;

	(void)ac;
	while (true)
	{
		show_prmpt(); /* Show the prompt */
		read_csize = getline(&usr_cmd, &usr_cmd_size, stdin); /*Get cmd 4rm ur*/
		if (read_csize == -1) /* check func failed or not EOF or use CTRL + D*/
		{	print_txt("Van Shell will Exit now...\n");
			return (-1);
		}
		cp_urs_cmd = malloc(sizeof(char) * read_csize);
		if (cp_urs_cmd == NULL)
		{	perror("Error encountered during malloc\n");
			return (-1);
		}
		strcpy(cp_urs_cmd, usr_cmd);
		to_ken = strtok(usr_cmd, delim);
		for (i = 0; to_ken != NULL; i++)
		{	tokenizer++;
			to_ken = strtok(NULL, delim);
		}
		tokenizer++;
		argv = malloc(sizeof(char *) * tokenizer);
		to_ken = strtok(cp_urs_cmd, delim);
		for (i = 0; to_ken != NULL; i++)
		{	argv[i] = malloc(sizeof(char) * strlen(to_ken));
			strcpy(argv[i], to_ken);
			to_ken = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execvp(argv[0], argv);
		free(cp_urs_cmd);
		free(usr_cmd);
	}
	return (0);
}
