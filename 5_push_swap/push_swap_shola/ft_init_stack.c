/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akakinad <akakinad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:46:42 by akakinad          #+#    #+#             */
/*   Updated: 2023/02/21 15:52:30 by akakinad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_chunks(int *totalnums, int *n)
{
	if (*totalnums <= 30)
		*n = 5;
	else if (*totalnums <= 150)
		*n = 8;
	else
		*n = 18;
}
