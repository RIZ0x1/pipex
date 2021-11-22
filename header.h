/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:17:59 by jcarlena          #+#    #+#             */
/*   Updated: 2021/11/22 18:18:00 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"

# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

# define ERR_ARG 0x1
# define ERR_NOTFOUND 0x2
# define ERR_NOSUCHFD 0x3

void	the_end(int exit);
void	child_process1(int fds[2], char *arg1, char *arg2, char **envp);
void	child_process2(int fds[2], char *arg3, char *arg4, char **envp);

#endif
