#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, int argv)
{
    char buffer[50];
    int c=1;

    argc = 11;
    sprintf(buffer, "From Child %d init n = %d, ",c,argc);
    printf("%s", buffer);
  while(argc > 1){
    if(argc % 2 == 0)
    { 
      argc = argc / 2;
      sprintf(buffer, "From Child %d init n = %d, ",c,argc);
      printf("%s", buffer);
    }
    else{ //for odd numbers
      argc = argc * 3 + 1;
      sprintf(buffer, "From Child %d init n = %d, ",c,argc);
      printf("%s", buffer);
    }
  }
  return 0;
}
