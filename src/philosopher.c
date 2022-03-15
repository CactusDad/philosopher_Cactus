#include <stdio.h>
#include "philosopher.h"
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

long long get_time(void)
{
	struct timeval time;
	long long mill_time;

	gettimeofday(&time, NULL);
	mill_time = time.tv_sec * 1000LL + time.tv_usec / 1000;
	return (mill_time);
}
int min(int i, int j)
{
	if (i < j)
		return (i);
	return (j);
}

int max(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}
int go = 0;
void *routine(void *table)
{
	t_table *t;

	t = ((t_table *)table);
	t->current_time = get_time();
	while (1)
	{
		pthread_mutex_lock(&t->fork[min(t->philos->id, (t->philos->id + 1) % t->num_philo)]);
		pthread_mutex_lock(&t->fork[max(t->philos->id, (t->philos->id + 1) % t->num_philo)]);
		// system("clear");
		// long long sec = (get_time() - ((t_table *)table)->current_time);
		// if (sec >= 200)
		// {
		// 	printf("%lld\n", sec);
		// 	break;
		// }
		printf("num:%d\n",go++);
		pthread_mutex_unlock(&t->fork[t->philos->id]);
		pthread_mutex_unlock(&t->fork[(t->philos->id + 1) % t->num_philo]);
	}
	return (NULL);
}

void philo_init(t_table *table, int num)
{
	int i;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * num + 1);
	while (i < num)
	{
		if (pthread_create(&table->philos[i].philo, NULL, routine, table) != 0)
		{
			printf("Failed to create thread\n");
			break;
		}
		table->philos->id = i;
		i++;
	}
}

void wait_thread(t_table *table, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		if (pthread_join(table->philos[i].philo, NULL) != 0)
		{
			printf("Faild to join thread\n");
			break;
		}
		i++;
	}
}
void mutex_init(t_table *table, int num)
{
	int i;

	i = 0;
	table->fork = malloc(sizeof(pthread_mutex_t) * num + 1);
	while (i < num)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		i++;
	}
}

void mutex_destroy(t_table *table, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_table table;

	table.num_philo = atoi(argv[1]);
	// gettimeofday(&table.last_time, NULL);
	if (argc < 4)
	{
		printf("Missing args\n");
		return (0);
	}
	mutex_init(&table, table.num_philo);
	philo_init(&table, table.num_philo);
	wait_thread(&table, table.num_philo);
	mutex_destroy(&table, table.num_philo);
	return (0);
}
