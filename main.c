#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdlib.h>
void function(int N,int c)
{
    char buffer[50];
    
    sprintf(buffer, "From Child %d init n = %d, ",c,N);
    printf("%s", buffer);
  while(N > 1){
    if(N % 2 == 0)
    { 
      N = N / 2;
      sprintf(buffer, "From Child %d n = %d, ",c,N);
      printf("%s", buffer);
    }
    else{ //for odd numbers
      N = N * 3 + 1;
      sprintf(buffer, "From Child %d n = %d, ",c,N);
      printf("%s", buffer);
    }
  }
  printf("\n\n");
}

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);

    // child process because return value zero
    if (fork() == 0)
        function(x+3,2);
    // parent process because return value non-zero.
    else
    {  
        function(x,1);
        wait(0);
        printf("Children Completed");
        
    }
    return 0;
}
