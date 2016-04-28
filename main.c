#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct	s_thread_info
{
	pthread_t	thread_id;
	int			thread_num;
	char		*argv_string;
}				thread_info;

static void *thread_start(void *arg)
{
	thread_info *tinfo = arg;
	char *uargv;
	char *p;

	printf("Thread %d: top of stack neat %p; argv = %s\n",tinfo->thread_num, &p, tinfo->argv_string);
	uragv = strdup(tinfo->argv_string);
	if (uargv == NULL)
	{
		printf("error strdup\n");
		exit(4);
	}
	p = uargv;
	while (*p)
		*p = toupper(*p);
	return uargv;
}

int main(int argc, char *argv[])
{
	int				s;
	int				tnum;
	int				opt;
	int				num_threads;
	int				stack_size;
	pthread_attr_t	attr;
	void			*res;

	stack_size = -1;
	while ((opt = getopt(argc, argv, "s:")) ! = -1)
	{
		switch (opt)
		{
			case 's':
				stacck_size = strtoul(optarg, NULL, 0);
				break;
			default:
				fprintf(stderr, "Usage: %s [-s stack-size] arg..\n", argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	num_threads = argc - optind;
	s = pthread_attr_init(&attr);
	if (s != 0)
	{
		printf("error pthread attr\n");
		exit(4);
	}
	if (stack_size)
}
/* void	*my_thread_process(void *arg) */
/* { */
/* 	int i; */
/*  */
/* 	i = 0; */
/* 	while (i < 5) */
/* 	{ */
/* 		printf("Thread %s: %d\n", (char *)arg, i); */
/* 		sleep(1); */
/* 		i++; */
/* 	} */
/* 	pthread_exit(0); */
/* } */
/*  */
/* int main(int ac , char **av) */
/* { */
/* 	pthread_t th1; */
/* 	pthread_t th2; */
/* 	void *ret; */
/*  */
/* 	if (pthread_create(&th1, NULL, my_thread_process, "1") < 0) */
/* 	{ */
/* 		printf("pthread_create error for thread 1"); */
/* 		exit(3); */
/* 	} */
/*  */
/* 	if (pthread_create(&th2, NULL, my_thread_process, "2") < 0) */
/* 	{ */
/* 		printf("pthread_create error for thread 1"); */
/* 		exit(3); */
/* 	} */
/*  */
/* 	(void)pthread_join(th1, &ret); */
/* 	(void)pthread_join(th2, &ret); */
/* } */
