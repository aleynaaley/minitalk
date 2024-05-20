#include "minitalk.h"

static void	print_pid(pid_t pid)
{
	char	i;

	if (pid > 9)
	{
		print_pid((pid / 10));
		print_pid((pid % 10));
	}
	else
	{
		i = 48 + pid;
		write(1, &i, 1);
	}
}

static void	signal_handler(int signal)
{
	static char	chr = 0;
	static int	bit = 0;

	if (signal == SIGUSR1)
		chr = (chr << 1) | (1);
	if (signal == SIGUSR2)
		chr = (chr << 1) | (0);
	bit++;
	if (bit == 8)
	{
		write(1, &chr, 1);
		bit = 0;
		chr = 0;
	}
}

int	main(void)
{
	pid_t	process_id;

	process_id = getpid();
	print_pid(process_id);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
