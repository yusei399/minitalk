/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:16:11 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/08/26 09:16:14 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bits(int pid, char c)
{
	unsigned int	one;
	unsigned int	and;
	unsigned int	j;

	j = 0;
	one = 0b10000000;
	while (j < 8)
	{
		and = c & one;
		if (and == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep (800);
		c = c << 1;
		j++;
	}
}

int	main(int ac, char **argv)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		write(1, "Invalid\n", 10);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			bits(pid, argv[2][i]);
			i++;
		}
		bits(pid, argv[2][i]);
	}
	return (0);
}
