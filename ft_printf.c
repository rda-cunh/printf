/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:17:42 by rda-cunh          #+#    #+#             */
/*   Updated: 2023/11/28 18:59:26 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "../libft/libft.h"

void	ft_printf(const char *format, ...)
{
	va_list	args;
	
	va_start(args, format);
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			if(*format == 'd')
			{
				printf("%d", va_arg(args, int));
			}
			else if (*format == 's')
			{
				printf("%s", va_arg(args, char *));
			}
			else 
			{
				putchar(*format);
			}
			format++;
		}
	}
	va_end(args);
}

int	main(void)
{
	ft_printf("Hello %s, number is %d\n", "World", 42);
	return (0);
}