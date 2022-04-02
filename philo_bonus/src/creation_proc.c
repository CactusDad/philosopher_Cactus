#include "philo_bonus.h"
#include <semaphore.h>
void    init_semaphore(t_philo *philo)
{
  philo->state->forks = sem_open ("Open_Sema", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, philo->state->num_of_philos);
}
void    init_childs(t_philo philo)
{
    int i;

    i = 0;
    philo.state->start_time = get_time();
    while (i < philo.state->num_of_philos)
    {
        philo.index = i;
       
        philo.pid = fork();
        if( philo.pid == 0)
        {
            routine(&philo);
            return ;
        }
        // usleep(10);
        i++;
    }
}

void    wait_child(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->state->num_of_philos)
    {
        waitpid(philo[i].pid, NULL, 0);
        i++;
    }
}