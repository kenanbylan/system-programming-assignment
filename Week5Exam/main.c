#include <stdio.h>
#include <pthread.h>


int main() {
  pid_t pid;
  int vari = 100;
  pid = fork();

  if( pid == 0){
      vari = 200;
  }
  fork()
  printf("%d", vari);
}
