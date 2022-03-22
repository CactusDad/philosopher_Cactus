#include "philosopher.h"

int	ft_is_numbers_error(char **numbers, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
	j = 0;
		while (numbers[i][j])
		{
			if ((numbers[i][j] == '-' && numbers[i][j + 1] == '\0')
				|| (numbers[i][j] == '+' && numbers[i][j + 1] == '\0'))
				return (1);
			if ((!ft_isdigit(numbers[i][j]))
			&& numbers[i][j] != '+' && numbers[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

