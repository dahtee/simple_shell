#include "shell.h"
/**
 * print_txt - Print String to the Standard Output.
 * @usr_message: user inputted text.
 * Return: Nothing is returned.
 */
void print_txt(const char *usr_message)
{
	write(STDOUT_FILENO, usr_message, strlen(usr_message));
}
