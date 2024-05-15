/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:13:15 by alerkul           #+#    #+#             */
/*   Updated: 2024/04/29 18:13:17 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


void send_signal(pid_t pid, int bit)
{
    if (bit == 1)
        kill(pid, SIGUSR1);
    else if (bit == 0)
        kill(pid, SIGUSR2);
}

void found_bit(pid_t pid, char chr)
{
    int i;
	int bit;

    for (i = 0; i < 8; i++)
    {
		bit = (chr >> (7 - i)) & 1;
        send_signal(pid, bit);
        usleep(100);  // Sinyal gönderimi arasında kısa bir gecikme
    }
}


int main(int argc, char **argv)
{
    pid_t process_id;
	int i;

	i = 0;
    if(argc == 3)
    {
        process_id = ft_atoi(argv[1]);
		while(argv[2][i])
		{
        	found_bit(process_id,argv[2][i]);
			i++;
		}
    }
    else
        write(1,"The number of arguments you entered is incorrect, enter only 3 arguments",72);
    return 0;
}

