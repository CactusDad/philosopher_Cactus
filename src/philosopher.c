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
void	take_fork(int id, int time, int state)
{
	if (state)
		printf("%d %d has taken a right fork\n",time, id);
	else
		printf("%d %d has taken a left fork\n",time, id);

}

void	eating(int id)
{
	printf("timestamp_in_ms %d is eating\n", id);
	usleep(1000);
}

void	thinking(int id)
{
	printf("timestamp_in_ms %d is thinking\n",id);
	usleep(1000);
}
void	sleeping(int id)
{
	printf("timestamp_in_ms %d is sleeping\n", id);
	usleep(1000);
}
void *routine(void *philo)
{
	t_philo *t;
		t = ((t_philo *)philo);
	while(1)
	{
		// printf("id: %d\n",t->id);
		pthread_mutex_lock(&t->ptrfork[min(t->id, (t->id + 1) % t->num)]);
		take_fork(t->id, get_time(), 1);
		pthread_mutex_lock(&t->ptrfork[max(t->id, (t->id + 1) % t->num)]);
		take_fork(t->id, get_time(), 0);
		eating(t->id);
		// sleep(1);
		pthread_mutex_unlock(&t->ptrfork[(t->id + 1) % t->num]);
		pthread_mutex_unlock(&t->ptrfork[t->id]);
		sleeping(t->id);
		thinking(t->id);
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
		
		table->philos[i].id = i;
		table->philos[i].num = num;
		table->philos[i].ptrfork = table->fork;
		if (pthread_create(&table->philos[i].philo, NULL, routine, &table->philos[i]) != 0)
		{
			printf("Failed to create thread\n");
			break;
		}
		// printf("hey%d\n",table->philos[i].id);
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
	int philo_num;

	philo_num = atoi(argv[1]);
	// gettimeofday(&table.last_time, NULL);
	if (argc < 4)
	{
		printf("Missing args\n");
		return (0);
	}
	mutex_init(&table, philo_num);
	philo_init(&table, philo_num);
	wait_thread(&table, philo_num);
	mutex_destroy(&table, philo_num);
	return (0);
}
