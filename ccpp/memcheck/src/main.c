
#include <stdio.h>
#include <stdlib.h>

void func(){

   int *ptr ;
   ptr =(int*) malloc(sizeof(int)*10);
      
   ptr[10]= 0;
 
}


int main(int argc,const char *argvs[])
{

    func();
     return 0;

}

