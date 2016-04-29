#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_THREADS 5

void	*print_hello(void *threadid)
{
	long tid;
	tid = (long)threadid;
	printf("executing...the function in the thread #%ld\n", tid);
	printf("hello world it's me thread #%ld!\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;

	t = 0;
	while (t < NUM_THREADS)
	{
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);
		if (rc)
		{
			printf("error, return frim pthread creation\n");
			exit(4);
		}
		t++;
	}
	// the last thing the main should do
	pthread_exit(NULL);
}
