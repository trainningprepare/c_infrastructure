#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>





int main(int argc,const char* argvs[]){

  int port = 9096;
  int sockfd = init_server(port);

  int epfd = epoll_create(1);

  struct epoll_event ev,events[1024];
  ev.events = EPOLLIN;
  ev.data.fd = sockfd;
  epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&ev)

   while(1)
   {
     int nready = epoll_wait(sockfd);
     int i;
	 for(i=0;i<nready;++i)
	 {
	  int connfd = events[i].data.fd;
	  if (connfd==sockfd)
	  	{
            while(1)
            {



			}
		
	    }

	 
	 }
  	 
   }
 

   return 0;
}



