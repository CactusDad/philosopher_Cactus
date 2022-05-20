#include<philosopher.h>

void    messages(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->state->print_lock);
    if (philo->state->death != 1)
    {
        printf("%lld ", get_current_time(philo));
        printf("%d %s\n", philo->id + 1, str);
    }
    pthread_mutex_unlock(&philo->state->print_lock);
}