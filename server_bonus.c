/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:18:43 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/08/31 06:23:05 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	send_msg(int *var, int *result, siginfo_t *t)
{
	if (*var == 8)
	{
		if (*result == 0)
		{
			kill(t->si_pid, SIGUSR1);
		}
		else
			ft_putchar(*result);
		*result = 0;
		*var = 0;
	}
}

void	reset(int *var, int *result, int pid)
{
	g_pid = pid;
	*var = 0;
	*result = 0;
}

void	sig_handler(int sig, siginfo_t *t, void *b)
{
	static int	var;
	static int	result;

	(void)b;
	if (g_pid != t->si_pid)
		reset(&var, &result, t->si_pid);
	if (sig == SIGUSR1)
	{
		result *= 2;
		result = result + 1;
		var++;
		send_msg(&var, &result, t);
	}
	else
	{
		result *= 2;
		result = result + 0;
		var++;
		send_msg(&var, &result, t);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	write(1, "PID : ", 6);
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
}
