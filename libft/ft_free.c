/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 02:52:11 by administrat       #+#    #+#             */
/*   Updated: 2022/08/26 02:09:07 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ultimate_free(char ***s)
{
	size_t	i;

	i = 0;
	while (*s[i])
		free (*s[i++]);
	*s = NULL;
}
