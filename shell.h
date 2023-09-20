#ifndef SHELL_H
#define SHELL_H

/**
 * include - here is the include files
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/stat.h>

/**
 * prototype - This section it my custom prototypes.
 */

void show_prmpt(void);
void print_txt(const char *usr_message);
void evoke_user_command(char **ur_args);
char *usr_cmd_placehold(char *command);



#endif
