/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:17:49 by jcarlena          #+#    #+#             */
/*   Updated: 2021/11/22 20:39:40 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define CHILD 0

int	main(int argc, char **argv, char **envp)
{
	int	fds[2];
	int	child_pid1;
	int	child_pid2;

	child_pid1 = 0;
	child_pid2 = 0;
	errno = 0;
	if (argc != 5)
		the_end(ERR_ARG);
	if (pipe(fds) == -1)
		the_end(0);
	child_pid1 = fork();
	if (child_pid1 == -1)
		the_end(0);
	if (child_pid1 == CHILD)
		child_process1(fds, argv[1], argv[2], envp);
	wait(0);
	child_pid2 = fork();
	if (child_pid2 == -1)
		the_end(0);
	if (child_pid2 == CHILD)
		child_process2(fds, argv[3], argv[4], envp);
	return (0);
}
