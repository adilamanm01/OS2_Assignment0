#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

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
  printf("\n");
}


// Driver code
int main(int argc, char* argv[])
{
	int pid, pid1, pid2;
	int x = atoi(argv[1]);

	pid = fork();

	// If fork() returns zero then it
	// means it is child process.
	if (pid == 0) {
            
            if(x>0 || x<40)
            function(x,1);
	}

	else {
		pid1 = fork();
		if (pid1 == 0) {
			function(x+3,2);
		}
		else {
			   wait(0);
				printf("Children Completed\n");
			
		}
	}

	return 0;
}
