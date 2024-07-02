#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int global = 0;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Nieprawidlowa ilosc argumentow!\n");
        return 22;
    }
    printf("nazwa obecnego programu: %s\n", argv[0]);

    int local = 20;
    int child_pid = fork();

    switch (child_pid) {
        case -1: printf("error: could not create child process");
        case 0: {
            printf("child process\n");
            global++;
            local++;
            printf("child pid = %d, parent pid = %d\n", (int) getpid(), (int) getppid());
            printf("child's local = %d, child's global = %d\n", local, global);
            execl("/bin/ls", "ls", argv[1], NULL);
        }
        default: {
            int child_exit_code;
            printf("parent process\n");
            printf("parent pid = %d, child pid = %d\n", (int) getpid(), child_pid);
            wait(&child_exit_code);
            printf("child exit code: %d\n", WEXITSTATUS(child_exit_code));
            printf("parent's local = %d, parent's global = %d\n", local, global);
            return 0;
        }
    }
    return 0;
}