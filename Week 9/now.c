// Program that uses posix_spawn to create several child processes

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

int main(void) {

    // date +%d-%m-%Y
    
    pid_t date_pid;
    
    char *date_args[] = {"/usr/bin/date", "+%d-%m-%Y", NULL};
    if (posix_spawn(&date_pid, "/usr/bin/date", NULL, NULL, date_args, environ) != 0) {
        perror("posix_spawn");
        exit(1);
    };
    
    // Wait for spawned process to finish
    int date_exit_status;
    if (waitpid(date_pid, &date_exit_status, 0) == -1) {
        perror("waitpid");
        exit(1);
    }

    printf("/usr/bin/date exit status was %d\n", date_exit_status);
    
    
    // hostname -f
    
    pid_t pid2;
    char *hostname_args[] = {"/usr/bin/hostname", "-f", NULL};
    if (posix_spawn(&pid2, "/usr/bin/hostname", NULL, NULL, hostname_args, environ) != 0) {
        perror("posix_spawn");
        exit(1);
    };
    
    int hostname_exit_status;
    if (waitpid(pid2, &hostname_status, 0) == -1) {
        perror("waitpid");
        exit(1);
    }
    
    printf("/usr/bin/hostname exit status was %d\n", hostname_exit_status);

    return 0;
}