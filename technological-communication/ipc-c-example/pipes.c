#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<stdio.h>

int main() {
  int pipe_fd[2];

  if (pipe(pipe_fd) == -1) {
    fputs("Unable to create the pipe", stderr);
    exit(EXIT_FAILURE);
  }

  int child_pid = fork();

  if (child_pid == -1) {
    fputs("Unable to fork a child process", stderr);
    exit(EXIT_FAILURE);
  }
  else if (child_pid == 0) {
    close(pipe_fd[1]);
    
    char buf;
    while (read(pipe_fd[0], &buf, 1) > 0)
      putchar(buf);
    putchar('\n');

    close(pipe_fd[0]);

    exit(EXIT_SUCCESS);
  }
  else {
    close(pipe_fd[0]);
    
    char message[] = "Hello from parent process!\n";
    write(pipe_fd[1], message, sizeof(message));

    close(pipe_fd[1]);

    wait(NULL);
    exit(EXIT_SUCCESS);
  }
}
