#include "shell.h"

/**
 * evoke_command - Execute a command and print its exit status.
 * @cmd: The command to execute.
 */
void evoke_command(const char *cmd)
{
    pid_t new_pid;
    char **usr_args;
    int i;

    usr_args = malloc(128 * sizeof(char *));
    if (usr_args == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    new_pid = fork();

    if (new_pid < 0)
    {
        perror("fork failed");
        free(usr_args);
        exit(EXIT_FAILURE);
    }

    if (new_pid == 0)
    {
        if (execv("/bin/echo", usr_args) == -1)
        {
            perror("execv failed");
            free(usr_args);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int status;
        waitpid(new_pid, &status, 0);

        if (WIFEXITED(status))
        {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
        else
        {
            print_txt("Child terminated abnormally\n");
        }

        free(usr_args);
    }
}

int main()
{
    evoke_command("/bin/echo");
    return 0;
}
