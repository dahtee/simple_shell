#include "shell.h"
/**
 * user_input - Accepts User input from stream.
 * @cmd: user input.
 * @size_of_str: the length of the string from user.
 * Return: Nothing since return void.
 */

void user_input(char *cmd, size_t size_of_str)
{
	if (fgets(cmd, size_of_str, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_txt("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_txt("Error during Parsing of input.\n");
			exit(EXIT_FAILURE);
		}
	}
	cmd[strcspn(cmd, "\n")] = '\0'; /*remove newline*/
}
