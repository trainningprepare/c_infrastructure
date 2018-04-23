#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

int writeToFile(int fd ,const char *buf,int whence)
{
    const char * copy= buf;
    if (copy==0) return -1;
    int left=whence,writelen=0;
    int nwrite = 0;
    int errorflag = 0;
    while(left>0)
    {
      
     nwrite = write(fd,buf,left);
     if (nwrite<0)
     {
       nwrite = -errno;
       if (nwrite==EBADF)
       {
           break;
       }else if (nwrite==EAGAIN || nwrite==EINTR)
       {
          continue;
          
       }
    }else if (nwrite==0){
          break;
   }
   
    writelen+=nwrite;
    left = left - nwrite;
}
    if (left>0) return -1;
    return 0;     

}



int main(int argc,const char**argvs)
{
 
   const char* str = "wenweipfsdfsakdfjaskdfjsakldfjaslkfdjaldfkjadjdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddingfsdkflsjflas fdalfjaklfja fa fd hello world\n";
   int len = strlen(str);
   writeToFile(1,str,len);
   


  return 0;
}

