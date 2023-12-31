/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:26:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/08/12 22:00:48 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "tables.h"
# include "macros.h"

//MAIN
void	expander(void);

//EXANDTEXT
void	expand_values_from_lexlist(void);
void	expand_text(t_lexlist *lex_table, int is_after_meta);

void	expand_order(char **dst, char **src);
void	expand_envs(char **dst, char *ptr);

void	expand_dollar(char **dst, char **src);
void	single_dollar(char **dst);
void	double_dollar(char **dst, char **src);
void	question_mark(char **dst, char **src);
void	expand_dollar_value(char **dst, char **src);

void	clear_void_contents(void);

//EXPANDCMD
void	expand_cmd(char **dst);
void	expand_from_env_value(char **dst, char *content);
char	*get_arg_from_env_value(char **envs, char *search_arg_name);

#endif
