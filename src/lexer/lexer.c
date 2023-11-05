/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:36:01 by akaniber          #+#    #+#             */
/*   Updated: 2023/10/13 20:29:22 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdlib.h>

int	cmd_build_other(int *i, int *len, char *cmd)
{
	int	a;
	int	tmp;
	int	size;

	tmp = *i;
	size = *len;
	a = cmd[tmp];
	while (size > 0)
	{
		if (cmd[tmp++] == a)
		{
			*i += 1;
			*len -= 1;
			size--;
			if (size % 2 == 0)
				return (1);
		}
	}
	return (0);
}

void	cmd_build_(char *cmd, int *len, int *i)
{
	int	tmp;
	int	a;
	int	j;

	j = *i;
	tmp = *len;
	a = cmd[j];
	while (tmp > 0)
	{
		if (cmd[j] == a)
		{
			*i += 1;
			j++;
			*len -= 1;
			tmp--;
			if (tmp % 2 == 0)
				break ;
		}
		*i += 1;
		j++;
	}
}

char	*cmd_build(char *cmd)
{
	int	len;
	int	i;
	int	size;

	i = 0;
	len = quote_len1(cmd);
	size = ft_strlen(cmd);
	while (i < size)
	{
		if (cmd[i] == '\"' || cmd[i] == '\'')
			cmd_build_(cmd, &len, &i);
		if (cmd[i++] == ' ')
			cmd[i - 1] = 2;
	}
	return (cmd);
}

void	lex_list(char *cmd, t_lexer **lex_table)
{
	char	**str;
	char	*str2;
	char	*data;
	int		i;
	t_list	*new_node;

	i = 0;
	data = cmd_build(cmd);
	str2 = set_build(data);
	str = ft_split(str2, 2);
	free(str2);
	if (!str)
		return ;
	while (str[i])
	{
		new_node = ft_lstnew(str[i]);
		ft_lstadd_back(&(*lex_table)->lex, new_node);
		i++;
	}
	free(str);
}

void	lexer(t_shell *shell)
{
	lex_list(shell->cmd, &(shell->lex_list));
}
