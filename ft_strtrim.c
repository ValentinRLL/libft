/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:56:41 by Valentin          #+#    #+#             */
/*   Updated: 2019/04/02 18:43:35 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		min;
	int		max;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	min = 0;
	max = ft_strlen(s) - 1;
	while ((s[min] == ' ' || s[min] == '\t' || s[min] == '\n') && s[min])
		min++;
	while ((s[max] == ' ' || s[max] == '\t' || s[max] == '\n') && max > min)
		max--;
	if (max - min > 0)
	{
		if (!(new = ft_memalloc(max - min + 1)))
			return (NULL);
	}
	else // error there, i have to deal without max-min and try with full read the string while there is no \t \n ' '
	{
		if (!(new = ft_memalloc(1)))
			return (NULL);
	}
	while (min <= max)
	{
		new[i] = s[min];
		i++;
		min++;
	}
	new[i] = '\0';
	return (new);
}

int		main(void)
{
	char	s1[] = "  \t \t \n   \n\n\n\t";
	printf("%s\n", ft_strtrim(s1));
	return 0;
}
