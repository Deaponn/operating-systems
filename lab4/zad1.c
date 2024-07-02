#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Nieprawidlowa ilosc argumentow!\n");
        return 22;
    }

    int processes_count;
    int child_pid;

    sscanf(argv[1], "%d", &processes_count);

    for (int i = 0; i < processes_count; i++) {
        child_pid = fork();
        if (child_pid == 0) {
            printf("pid rodzica: %d, pid obecnego procesu: %d\n", (int) getppid(), (int) getpid());
            return 0;
        }
    }

    if (child_pid != 0) {
        while (wait(NULL) != -1);
        printf("koniec procesu macierzystego, argument wejsciowy: %d\n", processes_count);
    }

    return 0;
}