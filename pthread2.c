#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 4

void	*busy_work(void *t)
{
	int		i;
	long	tid;
	double	result;

	result = 0.0;
	tid = (long)t;
	printf("Thread %ld starting...\n", tid);
	for(i = 0; i < 1000000; i++)
		result = result + sin(i) * tan(i);
	printf("Thread %ld done. Result = %e\n", tid, result);
	pthread_exit((void *) t);
}

int		main(int argc, char *argv[])
{
	pthread_t		thread[NUM_THREADS];
	pthread_attr_t	attr;
	int				rc;
	long			t;
	void			*status;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for (t = 0; t < NUM_THREADS; t++)
	{
		printf("Main: creating thread %ld\n", t);
		rc = pthread_create(&thread[t], &attr, busy_work, (void *)t);
		if (rc)
		{
			printf("error in pthread create return code is %d\n", rc);
			exit(4);
		}
	}

	//free attribute and wait for the other threads
	pthread_attr_destroy(&attr);
	for (t = 0; t < NUM_THREADS; t++)
	{
		rc = pthread_join(thread[t], &status);
		if (rc)
		{
			printf("error in pthread join return code is %d\n", rc);
			exit(4);
		}
		printf("Main: completed join with thread %ld having a status of %ld\n", t, (long)status);
	}
	printf("Main: program completed. Exiting.\n");
	pthread_exit(NULL);
}
