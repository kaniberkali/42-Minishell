/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaybaz < aaybaz@student.42kocaeli.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:31:03 by aaybaz            #+#    #+#             */
/*   Updated: 2023/10/23 21:53:52 by aaybaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	get_env_utils(t_list **data, char *tmp, char *tmp2)
{
	char	*tmp3;

	tmp3 = ft_strdup((*data)->content);
	free((*data)->content);
	(*data)->content = quote_control(tmp3);
	free_tmp_tmp2(tmp, tmp2, tmp3);
	(*data) = (*data)->next;
}

int	is_space(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (cmd[i] == '\0')
		return (0);
	return (1);
}

int	print_error(void)
{
	printf("%s\n", "minishell: syntax error near unexpected token");
	return (0);
}
