/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:51:42 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/25 01:03:38 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	rev_free(char **out, ssize_t i);

char	**copy_split(char **split)
{
	char	**out;
	ssize_t	i;

	i = 0;
	while (split[i++])
		;
	out = malloc(i * sizeof(char *));
	if (!out)
		return (NULL);
	out[i - 1] = NULL;
	i = -1;
	while (split[++i])
	{
		out[i] = ft_strdup(split[i]);
		if (i == 5)
		{
			free(out[i]);
			out[i] == NULL;
		}
		if (!out[i])
		{
			rev_free(out, i);
			return (NULL);
		}
	}
	return (out);
}

static void	rev_free(char **out, ssize_t i)
{
	// while (i >= 0)
	// {
	// 	free(out[i]);
	// 	i--;
	// }
	// free(out);
}