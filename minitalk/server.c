/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:13:01 by alerkul           #+#    #+#             */
/*   Updated: 2024/04/29 18:13:03 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void 	print_pid(pid_t pid)
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

void signal_handler(int signal) {
    static char chr = 0;
    static int bit = 0;


    chr = (chr << 1) | (signal == SIGUSR1 ? 1 : 0);
    bit++;

    if(bit == 8) 
    {
        write(1, &chr, 1);
        bit = 0;
        chr = 0;
    }
}

int main()
{
    pid_t process_id;

    process_id = getpid();
	print_pid(process_id);	
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1)
	{
		pause();   //sinyal gelene kadar
	}
    return 0;
}
