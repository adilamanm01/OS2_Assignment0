#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main(int argc, int argv) 
{
    int n,max=200,i,c=1;
    int a[100];

   for(i=0;i<200;i++)
   {
    if(n<0)
    printf("invalid entry");
    else
    {
        if(n%2==0)
        {
            n=n/2;
            scanf("%d",&a[i]);
            n=a[i];
            c=c+1;
        }
        else{
                n=(3*n)+1;
                scanf("%d",&a[i]);
                n=a[i];
                c=c+1;
        }

    }
   }
   for(i=0;i<c;i++)
   printf(" %d ",a[i]);
   return 0;
} 

