/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akakinad <akakinad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:47:10 by akakinad          #+#    #+#             */
/*   Updated: 2023/02/27 14:47:13 by akakinad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	size_t	i;
	char	*s;
	char	*n;

	s = (char *)stack;
	n = (char *)needle;
	i = 0;
	if (!s)
		return (NULL);
	if (n[0] == '\0')
		return ((char *)stack);
	while (s[i] && i < len)
	{
		if (s[i] == n[0])
		{
			if (!ft_strncmp(&s[i], n, ft_strlen(n))
				&& ft_strlen(n) + i <= len)
				return (&s[i]);
		}
		i++;
	}
	return (0);
}
