#include "shell.h"
/**
 * main - main entry point of code
 *
 * Return: 0 if code is true.
 */
int main(void)
{
	char usr_command[128];

	while (true)
	{
		show_prmpt();
		user_input(usr_command, sizeof(usr_command));
		evoke_command(usr_command);
	}
	return (0);
}
