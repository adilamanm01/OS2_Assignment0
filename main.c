//declaring the required library
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<stdlib.h>

//declaring the function with logic 
void function(int N,int c)
{
    //Creating a buffer to store a string 
    char buffer[50];
    //storing a string in buffer using sprintf
    sprintf(buffer, "From Child %d init n = %d, ",c,N);
    printf("%s", buffer);
  //while loop for running the condition till the Given positive integer greater than 1
  while(N > 1){
    //Checking for Positive integer
    if(N % 2 == 0)
    { 
      //logic for even integer
      N = N / 2;
      //storing a string in buffer using sprintf
      sprintf(buffer, "From Child %d n = %d, ",c,N);
      printf("%s", buffer);
    }
    else{ 
      //logic for odd integer
      N = N * 3 + 1;
      sprintf(buffer, "From Child %d n = %d, ",c,N);
      printf("%s", buffer);
    }
  }
  printf("\n");
}

//declaring main function using argc and argv
int main(int argc, char *argv[])
{
    //converting into integer type
    int x = atoi(argv[1]);

    // if condition is a child process because returns value zero
    if (fork() == 0)
        //usinf the function
        function(x+3,2);
    // else condition is a parent process because returns value non-zero.
    else
    {   //using the function
        function(x,1);
        //using wait() to wait for child to complete the process
        wait(0);
        printf("Children Completed");
        
    }
    return 0;
}
