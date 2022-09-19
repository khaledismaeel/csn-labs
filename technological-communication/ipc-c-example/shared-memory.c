#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/mman.h>
#include <stdio.h>

int main()
{
#define SIZE 4

  int *shared = mmap(NULL, SIZE * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, 0, 0);

  if (shared == MAP_FAILED)
  {
    fputs("Failed to create shared memory", stderr);
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < SIZE; i++)
    shared[i] = i;

  puts("Before forking child:");
  for (int i = 0; i < SIZE; i++)
    printf("%d ", shared[i]);
  putchar('\n');

  int child_pid = fork();

  if (child_pid == 0)
  {
    for (int i = 0; i < SIZE; i++)
      shared[i] *= 2;
  }
  else
  {
    wait(NULL);

    puts("After forking child:");
    for (int i = 0; i < SIZE; i++)
      printf("%d ", shared[i]);
    putchar('\n');
  }

  exit(EXIT_SUCCESS);
}
