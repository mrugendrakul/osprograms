#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t cpid;
    char buf;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        return 1;
    }

    if (cpid == 0) { // Child reads from pipe
        close(pipefd[1]); // Close unused write end

        while (read(pipefd[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(0);
    } else { // Parent writes to pipe
        close(pipefd[0]);
        write(pipefd[1], "Hello from parent!", 18);
        close(pipefd[1]); // Reader will see EOF
        wait(NULL); // Wait for child
        return 0;
    }
}