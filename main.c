/*
Name : Adil Aman Mohammed 
CWID : A20395630
Description : The following code is an implimentation of fork() to create 2 child's and 1 parent for solving collatz Conjecture
*/

//Declaring Required libraries 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


//Declaration of function
void function(int N,int c)
{
  //Declaration of char type variable to store the string
    char buffer[50];
    //using sprintf to store the combined string in to a char variable
    sprintf(buffer, "From Child %d init n = %d, ",c,N);
    //displaying the buffer usinf printf
    printf("%s", buffer);
  //while loop for running the loop till n is less than 1
  while(N > 1){
    //logic of collatz conjecture
    if(N % 2 == 0) // logic for even numbers
    { 
      N = N / 2;
      //using sprintf to store the combined string in to a char variable
      sprintf(buffer, "From Child %d n = %d, ",c,N);
      //displaying the buffer usinf printf
      printf("%s", buffer);
    }
    else{ //logic for odd numbers
      N = N * 3 + 1;
      //using sprintf to store the combined string in to a char variable
      sprintf(buffer, "From Child %d n = %d, ",c,N);
      //displaying the buffer usinf printf
      printf("%s", buffer);
    }
  }
  //printing in new line
  printf("\n");
}


//Declaration of main function with argc and argv for command line input
int main(int argc, char* argv[])
{
  //declaring variables
	int pid, pid1;
  //converting a char type to integer type
	int x = atoi(argv[1]);
  //calling fork()
	pid = fork();
	//condition for input number limit
  if(x>0 && x<40)
  {
    // If fork() returns zero then it
	// means it is child process.
	if (pid == 0) {
    //child 1
    //calling function
            function(x,1);
	}

	else {

    //calling fork()
		pid1 = fork();
		if (pid1 == 0) {
      //child 2
      //calling function with a condition x+3
			function(x+3,2);
		}
		else {
      //parent
      //using wait() for children to complete the process
			   wait(&pid);
         wait(&pid1);
				printf("Children Completed\n");
			
		}
	}
  }
  else{
    printf("Invalid Entry\n");
  }

	return 0;
}
