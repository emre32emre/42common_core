/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:16:40 by mkocabas          #+#    #+#             */
/*   Updated: 2023/04/15 14:55:55 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_phlio
{
	int		phlio_id;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
}		t_phlio;


void milisecond_counter(int ms);
void second_counter(int seconds);

#endif