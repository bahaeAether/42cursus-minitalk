/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:11:27 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/05 00:11:40 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	safe_exit(int n)
{
	ft_putstr("Error :  failed to send signal\n");
	exit(n);
}

void	send_signal(int pid, char c)
{
	int	i;
	int	n;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			n = kill(pid, SIGUSR1);
		else
			n = kill(pid, SIGUSR2);
		if (n == -1)
			safe_exit(EXIT_FAILURE);
		usleep(400);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr("Error :  bad arguments\n");
		ft_putstr("Usage :  ./client [pid] [message]\n");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_str_is_numeric(argv[1]) == 0)
	{
		ft_putstr("Error :  bad pid\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 3)
	{
		while (argv[2][i])
			send_signal(ft_atoi(argv[1]), argv[2][i++]);
		send_signal(ft_atoi(argv[1]), '\n');
	}
	return (0);
}
