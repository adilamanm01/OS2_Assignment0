#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void function(int N)
{
    char buffer[50];
    int c=1;
    printf("%d  \n",N); //debug print for N
    sprintf(buffer, "From Child %d init n = %d, ",c,N);
    printf("%s", buffer);
  while(N > 1){
    if(N % 2 == 0)
    { 
      N = N / 2;
      sprintf(buffer, "From Child %d init n = %d, ",c,N);
      printf("%s", buffer);
    }
    else{ //for odd numbers
      N = N * 3 + 1;
      sprintf(buffer, "From Child %d init n = %d, ",c,N);
      printf("%s", buffer);
    }
  }
}


int main(int argc, char* argv[])
{
    int x = atoi(argv[1]);
    
    if(x>0 || x<40)
    function(x);
    
    return 0;
}
