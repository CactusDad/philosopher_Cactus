#include<stdio.h>
#include "philosopher.h"
#include<pthread.h>
#include<sys/time.h>
#include <unistd.h>
long long	get_time(void)
{
	struct timeval time;
	long long	mill_time;

	gettimeofday(&time, NULL);
	mill_time = time.tv_sec * 1000LL + time.tv_usec/1000;
	return (mill_time);
}
void	*routine(void *table)
{
	((t_table *)table)->current_time = get_time();
	while (1)
	{
		// system("clear");
		long long sec =  (get_time() - ((t_table *)table)->current_time);
		if (sec >= 200)
		{
			printf("%lld\n",sec);
			break;
		}
		
	}
	return (NULL);
}

void	initphilo(t_table *table, int num)
{
	int			i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * num + 1);
	while (i < num)
	{
		if (pthread_create(&table->philos[i].philo, NULL, routine, table) != 0)
		{
			printf("Failed to create thread\n");
			break ;
		}
		i++;
	}	
}

void	wait_thread(t_table *table, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_join(table->philos[i].philo, NULL) != 0)
		{
			printf("Faild to join thread\n");
			break ;
		}
		i++;
	}
}
	
int	main(int argc, char *argv[])
{
	t_table		table;

	(void)argc;
	// gettimeofday(&table.last_time, NULL);	
	if (argc < 4)
	{
		printf("Missing args\n");
		return (0);
	}
	initphilo(&table, atoi(argv[1]));
	wait_thread(&table, atoi(argv[1]));
	return (0);
}
