/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:07:11 by plettie           #+#    #+#             */
/*   Updated: 2019/06/06 18:49:52 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_valid.h"
#include <stdio.h>

static char		*ft_strchr(char *s, int resh)
{
	int		i;
    int count;

    count = 0;
	i = 0;
	while (s[i] != resh)
	{
		if (!s[i] || (s[i] != '.' && s[i] != '\n') || count > 3)
			return (0);
        if (s[i] == '\n')
            count++;
		i++;
	}
	return (&s[i]);
}

static int on_error(char **head)
{
    free(*head);
    *head = NULL;
    return (0);
}

static int is_sosed(char *c)
{
    int nei;

    nei = 0;
        if (*(c - 1) == '#')
            nei++;
        if (*(c + 1)== '#')
            nei++;
        if (*(c + 5)== '#')
            nei++;  
        if (*(c - 5) == '#')
            nei++;
    return (nei);
}

static int is_help(char *c)
{
    int count;
    int nei;

    count = 0;
    nei = 0;
    while (*c && count < 5)
    {
        c = ft_strchr(c, '#');
        if (!c)
            break;
        count++;
        if (!(nei += is_sosed(c)))
            return (0);
        c++;
    }
    if (count != 4)
        return (0);
    if (nei != 6 && nei != 8)
        return (0);
    nei = 0;
    return (1);
}

char is_valid(int fd)
{
    char *c = malloc(21);
    char *head;
    int kol;
    int time;
    int count;
    int flag;

    head = c;
    time = 0; 
    flag = 0;
    while ((kol = read(fd, c, 21)) > 0 && ++time < 27)
    {
        if (kol < 20 || c[4] != '\n' || (c[9] | c[14] | c[19] | c[kol - 1]) != c[4])
            return (on_error(&head));
        if (kol == 20)
            flag = 1;
    if (!(count = is_help(c)))
        return (on_error(&head));
        c = head;
    }
    if (kol == -1 || kol == 21 || time > 26 || flag == 0)
        return (on_error(&head));
    return (1);  
}

int main(int ac, char **av)
{
    int fd;

    if (ac != 2)
    {
        write(1, "usage", 5);
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    if (is_valid(fd))
        write(1, "harosh", 6);
    else
        write(1, "sore ne valid", 13);
    close (fd);
    return (0);
}
