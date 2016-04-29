#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static pthread_mutex_t my_mutex;
static int tab[5];

void	*read_tab_process(void *p)
{
	int i;

	pthread_mutex_lock(&my_mutex);
	for (i = 0; i != 5 ; i++)
		printf("read_process, tab[%d] vaut %d\n",i ,tab[i]);
	pthread_mutex_unlock(&my_mutex);
	pthread_exit(0);
}

void	*write_tab_process(void *p)
{
	int i;
	pthread_mutex_lock(&my_mutex);
	for (i = 0; i != 5; i++)
	{
		tab[i] = 2 * i;
		printf("write_process, tab[%d] vaut %d\n", i, tab[i]);
		sleep(1);
	}
	pthread_mutex_unlock(&my_mutex);
	pthread_exit(0);
}

int main (int ac, char **av)
{
	pthread_t	threads[2];
	void		*ret;

	pthread_mutex_init(&my_mutex, NULL);

	if (pthread_create(&threads[0], NULL, write_tab_process, (void *)"1") < 0)
	{
		printf("error create pthread 1\n");
		exit(2);
	}
	if (pthread_create(&threads[1], NULL, read_tab_process, (void *)"2") < 0)
	{
		printf("error create pthread 2\n");
		exit(2);
	}
	pthread_join(threads[0], &ret);
	pthread_join(threads[1], &ret);
}
