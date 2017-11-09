#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo){
  if(signo == SIGINT){
      FILE * log = fopen("log", "a");
      fputs("Program exited because of SIGINT\n", log);
      exit(0);
  }
  else if(signo == SIGUSR1){
    printf("PPID: %d\n", getppid());
  }
}

int main(){

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1){
    printf("PID: %d\n",getpid());
    sleep(1);
  }

  return 0;
}
