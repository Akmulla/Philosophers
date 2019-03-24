#include <stdio.h>
#include <pthread.h>  
#include <stdlib.h> 
#include <unistd.h>
#include <errno.h>
#define PORT 8080

enum TargetNode {next,prev};
enum State {thinking,eating};

int node_id = -1;

void ParseArgumentsForId(int argc, char** argv, int* node_id)
{
	int opt;
	//get node number from command line as the first and only argument
	if ((opt = getopt(argc,argv,"012")) != -1)
	{
		*node_id = opt - '0';
		printf("parsed node_id=%d\n",*node_id);
	}
	//close the program if there is no node number assigned
	else
	{
		printf("Missing Node ID command-line argument\n");
		exit(-1);
	}
}

void* ServerWork(void *arguments)
{
    printf("Server thread started\n");
    
    printf("Server thread finished\n");
}

void* ClientWork(void *arguments)
{
    printf("Clent thread started\n");
    
    printf("Clent thread finished\n");
}

int SendMessage(enum TargetNode target, char* message)
{
    
}

int AskForLeftFork()
{
    
}

int AskForRightFork()
{
    
}

int Activate()
{
    
}

int PutBackLeftFork()
{
    
}

int PutBackRightFork()
{
    
}

int FinishEating()
{
    
}

int Think()
{
    
}

int AskedForLeftFork()
{
    
}

int AskedForRightFork()
{
    
}

int main(int argc, char** argv)
{
    errno = 0;	
	pthread_t serverThreadId, clientThreadId;
    
    //figure out my id number
	ParseArgumentsForId(argc,argv,&node_id);
    
    //create thread with server socket
	if (pthread_create(&serverThreadId, NULL, ServerWork, NULL) !=0)
	{
		printf("Could not create server thread");
		return -1;
	}
	
	//create thread with client socket
        if (pthread_create(&clientThreadId, NULL, ClientWork, NULL)!=0)
	{
		printf("Could not create client thread");
		return -1;
	}
    
    pthread_join(serverThreadId, NULL);
 	pthread_join(clientThreadId, NULL);
    return 0;
}
