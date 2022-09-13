/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:18:57 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/08/26 09:18:59 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	ft_print(int *i, int *result)
{
	if (*i == 8)
	{
		ft_putchar(*result);
		*result = 0;
		*i = 0;
	}
}

void	reset(int *i, int *result, int pid)
{
	g_pid = pid;
	*i = 0;
	*result = 0;
}

void	sig_handler(int sig, siginfo_t *sig_info, void *b)
{
	static int	i;
	static int	result;

	(void)b;
	if (g_pid != sig_info->si_pid)
		reset(&i, &result, sig_info->si_pid);
	if (sig == SIGUSR1)
	{
		result *= 2;
		result = result + 1;
		i++;
		ft_print(&i, &result);
	}
	else
	{
		result *= 2;
		result = result + 0;
		i++;
		ft_print(&i, &result);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	write(1, "PID :", 6);
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.__sigaction_u.__sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
