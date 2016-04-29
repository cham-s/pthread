#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void	*starter(void *param)
{
	int	i;
	for (i = 0; i < 5; i++)
	{
		printf("Thread %s: %d\n", (char *)param, i);
		sleep(1);
	}
	pthread_exit(0);
}

int main (int ac, char **av)
{
	pthread_t	threads[2];
	void		*ret;

	if (pthread_create(&threads[0], NULL, starter, (void *)"1") < 0)
	{
		printf("error create pthread 1\n");
		exit(2);
	}
	if (pthread_create(&threads[1], NULL, starter, (void *)"2") < 0)
	{
		printf("error create pthread 2\n");
		exit(2);
	}
	pthread_join(threads[0], &ret);
	pthread_join(threads[1], &ret);
}
