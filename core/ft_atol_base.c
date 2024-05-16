/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/05/14 20:46:50 by pepie             #+#    #+#             */
/*   Updated: 2024/05/14 20:53:47 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:27:25 by pepie             #+#    #+#             */
/*   Updated: 2023/09/13 19:08:05 by pepie            ###   ########.fr       */
=======
/*   Created: 2023/09/11 16:27:25 by pepie             #+#    #+#             */
/*   Updated: 2024/05/07 11:59:06 by pepie            ###   ########.fr       */
>>>>>>> 6dc9f48 (Fix compile + Add atoi / atol base)
/*                                                                            */
/* ************************************************************************** */

#include "libft_core.h"

int	ft_str_get_base(char str, char*base)
{
	int	u;

	u = 0;
	while (base[u] != '\0')
	{
		if (str == base[u])
			return (u);
		u++;
	}
	return (-1);
}

int	verify_base(char*base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' )
			return (0);
		if (base[i] < 33 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

long	atol_base(char*str, char*base, int max_base)
{
	long	num;

	num = 0;
	while (ft_str_get_base(str[0], base) != -1)
	{
		num = num * max_base;
		num = num + ft_str_get_base(str[0], base);
		str++;
	}
	return (num);
}

<<<<<<< HEAD
long ft_atol_base(char *str, char *base)
{
	int     minus_count;
	int     max_base;
	long	num;
=======
long	ft_atol_base(char*str, char*base)
{
	int		minus_count;
	long	num;
	int		max_base;
>>>>>>> 6dc9f48 (Fix compile + Add atoi / atol base)

	max_base = verify_base(base);
	if (max_base == 0)
		return (0);
	num = 0;
	minus_count = 0;
	while (ft_str_is_whitespace(*str))
		str++;
<<<<<<< HEAD
	while (*str == '-' || *str == '+')
=======
	if (*str == '-' || *str == '+')
>>>>>>> 6dc9f48 (Fix compile + Add atoi / atol base)
	{
		if (*str == '-')
			minus_count++;
		str++;
	}
	num = atol_base(str, base, max_base);
	if (minus_count % 2 == 1)
		num = num * -1;
	return (num);
}
<<<<<<< HEAD
=======

/* int	main(void)
{
	printf("42:%d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("-42:%d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
	printf("42:%d\n", ft_atoi_base("   -+-2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-z", "0123456789abcdef"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", ""));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "+-0"));
	printf("0:%d\n", ft_atoi_base("   --------+-2a", "\t01"));
} */
>>>>>>> 6dc9f48 (Fix compile + Add atoi / atol base)