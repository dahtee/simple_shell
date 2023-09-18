#ifndef SHELL_H
#define SHELL_H
/**
 * where is the include files
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * This section it my custom prototypes.
 */

void print_txt(const char *usr_message);
void show_prmpt(void);
void evoke_command(const char *cmd);
void user_input(char *cmd, size_t size_of_str);

#endif
