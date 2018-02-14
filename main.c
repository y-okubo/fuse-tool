#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
  int p_id;
  int status;
  int return_code = 0;
  int fd[10];
  int rc;
  char buf[100];

  if ((p_id = fork()) == 0) {
    /* 子プロセス */
    printf("子プロセス開始\n");
    // sleep(3);
    for (int i = 0; i < 3; i++) {
      fd[i] = open("/Users/y-okubo/mnt/Users/y-okubo/test.txt", O_RDWR | O_APPEND);
      printf("fd[%d]: %d\n", i, fd[i]);
      read(fd[i], buf, 8);
    }

    for (int i = 0; i < 3; i++) {
      close(fd[i]);
    }
    printf("子プロセス終了\n");
  } else {
    /* 親プロセス */
    if (p_id != -1) {
      printf("親プロセス開始\n");
      for (int i = 0; i < 3; i++) {
        fd[i] = open("/Users/y-okubo/mnt/Users/y-okubo/test.txt", O_RDWR | O_APPEND);
        printf("fd[%d]: %d\n", i, fd[i]);
        read(fd[i], buf, 8);
      }

      for (int i = 0; i < 3; i++) {
        close(fd[i]);
      }

      wait(&status);
      printf("親プロセス終了\n");
    } else {
      perror("親プロセス : ");
      return_code = 1;
    }
  }

  return return_code;
}