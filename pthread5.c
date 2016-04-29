#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

static	sem_t my_sem;
int		the_end;

void	*thread_one(void *p)
{
	while (!the_end)
	{
		printf("Je t'attend !\n");
		sem_wait(&my_sem);
	}

	printf("OK, je sors !\n");
	pthread_exit(0);
}

void	*thread_two(void *p)
{
	register int i;
	for (i = 0; i < 5; i++)
	{
		printf("J'arrive %d!", i);
		sem_post(&my_sem);
		sleep(1);
	}

	the_end = 1;
	sem_post(&my_sem);
	pthread_exit(0);
}

int main (int ac, char **av)
{
	pthread_t	threads[2];
	void		*ret;

	sem_init(&my_sem, 0, 0);
	if (pthread_create(&threads[0], NULL, thread_one, NULL) < 0)
	{
		printf("error create pthread 1\n");
		exit(2);
	}
	if (pthread_create(&threads[1], NULL, thread_two, NULL) < 0)
	{
		printf("error create pthread 2\n");
		exit(2);
	}
	pthread_join(threads[0], &ret);
	pthread_join(threads[1], &ret);
}
