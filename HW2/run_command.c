/*
 * run_command.c :    do the fork, exec stuff, call other functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include "shell.h"

void run_command(char **myArgv) {
    pid_t pid;
    int stat;

    /* Create a new child process.
     * Fill in code.
	 */
    pid=fork();

    switch (pid) {

        /* Error. */
        case -1 :
            perror("fork");
            exit(errno);

        /* Parent. */
        default :
            /* Wait for child to terminate.
             * Fill in code.
			 */

            if(!(is_background(myArgv))){
                if (waitpid(pid, &stat, 0)==-1){
                    perror("waitpid");
                    exit(1);
                }
            }
            

            

            /* Optional: display exit status.  (See wstat(5).)
             * Fill in code.
			 */

            if(WIFSIGNALED(stat)){
                printf("%s terminated by signal %d.\n", myArgv[0], WTERMSIG(stat));
            }

            else if(WIFEXITED(stat)){
                printf("%s exited with status %d.\n", myArgv[0], WEXITSTATUS(stat));
            }

            else if(WIFSTOPPED(stat)){
                printf("%s stopped by signal %d.\n", myArgv[0], WSTOPSIG(stat));
            }



            return;

        /* Child. */
        case 0 :
            /* Run command in child process.
             * Fill in code.
			 */

            is_background(myArgv);

            execvp(myArgv[0], myArgv);

            /* Handle error return from exec */
			exit(errno);
    }
}
