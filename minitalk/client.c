#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + ((str[i] - '0') * sign);
		i++;
		if (num > 2147483647)
			return (-1);
		if (num < -2147483648)
			return (0);
	}
	return (num);
}

static void	send_signal(pid_t pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else if (bit == 0)
		kill(pid, SIGUSR2);
}

static void	found_bit(pid_t pid, char chr)
{
	int	i;
	int	bit;

	i = 0;
	if (chr >= 0 && chr <= 127)
	{
		while (i < 8)
		{
			bit = (chr >> (7 - i)) & 1;
			send_signal(pid, bit);
			i++;
			usleep(42);
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t	process_id;
	int		i;

	i = 0;
	if (argc == 3)
	{
		process_id = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			found_bit(process_id, argv[2][i]);
			i++;
		}
	}
	else
		write(1, "please enter only 3 arguments", 29);
	return (0);
}
