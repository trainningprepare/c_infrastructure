
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define BZ(buff,size) memset(buff,0,size)


void scan(const char* ip)
{
     int i=1024;
	 int Max= 65535;

	 for(;i<Max;++i)
	 {
       int tel_sock = socket(AF_INET,SOCK_STREAM,0);
	   struct sockaddr_in wire_add;
	   BZ(&wire_add, sizeof(wire_add));
	   wire_add.sin_port = htons(i);
	   wire_add.sin_family = AF_INET;
	   wire_add.sin_addr.s_addr = inet_addr(ip);

	   int ret = connect(tel_sock,(struct sockaddr*)wire_add,sizeof(wire_add));
	   if (ret>=0)
	   {
	    printf("port %d is open \n",i);
	   }
	   close(tel_sock);
	 }

}


int main(int argc,const char* argvs[])
{
   scan(argvs[1]);
 return 0;
}























