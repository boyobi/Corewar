/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:25:56 by mmatamou          #+#    #+#             */
/*   Updated: 2017/03/13 00:19:56 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include <stdio.h>

int		main(int argc, char **argv)
{
//	ft_putnbr(sizeof(int));
	if (argc == 1)
		return (print_description());
	ft_corewar(argc - 1, &(argv[1]));
	return (0);
}
