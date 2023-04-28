/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:27:12 by rtimsina          #+#    #+#             */
/*   Updated: 2023/04/17 15:51:36 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_errors(char *str)
{
	write(1, str, ft_strlen(str));
	//perror(str);
	exit(EXIT_FAILURE);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkdbl(long num, char **str, int pos)
{
	pos++;
	while (str[pos])
	{
		if (num == ft_atoi(str[pos]))
			return (1);
		pos++;
	}
	return (0);
}

int	ft_toobig(char *str)
{
	long num;
	int	len;

	len = ft_strlen(str);
	if (len >= 10 )
	{
		if (len == 11 && str[0] == '-' && str[10] != '9')
			return(1);
		else if (len == 10 && str[9] != '8' && str[9] != '9')
			return (1);
		else
			return (0);
	}
	num = ft_atoi(str);
	//printf("%lld\n", num);
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	return (0);
}
void	ft_check_args(int argc, char **av)
{
	int	i;
	long	tmp;
	char **str;

	i = 0;
	if (argc == 2)
		str = ft_split(av[1], ' ');
	else
	{
		i = 1;
		str = av;
	}
	
	while (str[i])
	{
		tmp = ft_atoi(str[i]);
		//printf("%ld\n", tmp);
		if ((ft_isnum(str[i])) == 0)
			ft_errors("Errors1\n");
		if (ft_checkdbl(tmp, str, i))
			ft_errors("Errors2\n");
		if (!ft_toobig(str[i]))
			ft_errors("Errors3\n");
		i++;
	}
	
}