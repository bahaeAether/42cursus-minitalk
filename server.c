/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:12:23 by baboulou          #+#    #+#             */
/*   Updated: 2023/05/05 00:35:06 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_signal(int sig)
{
	static int	i = 0;
	static char	c = 0;

	c = c << 1;
	if (sig == SIGUSR1)
		c++;
	if (++i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1337)
		pause();
}
