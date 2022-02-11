/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:20:13 by tgerdes           #+#    #+#             */
/*   Updated: 2021/10/15 18:09:49 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	slen(const char *s)
{
	size_t	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c] != '\0')
	{
		c++;
	}
	return (c);
}

void	ft_bzero(void *s, size_t n)
{
	char	*pchar1;

	pchar1 = s;
	while (n > 0)
	{
		*pchar1 = '\0';
		n--;
		pchar1++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	return (NULL);
}

void	*ft_malloc(size_t count, size_t size)
{
	void			*rtn_str;
	unsigned char	*tmp_str;

	rtn_str = malloc(count * size);
	if (!rtn_str)
		return (NULL);
	tmp_str = rtn_str;
	*tmp_str = '\0';
	return (rtn_str);
}

char	*prepare_string(int fd, int bytes_read, char *rtn_str, char **tmpstr)
{
	static char	buf[MAX_FD][BUFFER_SIZE + 1];

	while (!ft_strchr(buf[fd], '\n'))
	{
		if (*buf[fd])
			rtn_str = ft_strjoin(rtn_str, buf[fd]);
		bytes_read = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][bytes_read] = '\0';
		if (bytes_read <= 0 && !(*rtn_str))
		{
			free(rtn_str);
			return (NULL);
		}
		if (bytes_read < BUFFER_SIZE && !ft_strchr(buf[fd], '\n'))
		{
			rtn_str = ft_strjoin(rtn_str, buf[fd]);
			ft_bzero(buf[fd], 1);
			return (rtn_str);
		}
	}
	*tmpstr = ft_strjoin(rtn_str, buf[fd]);
	rtn_str = ft_substr(*tmpstr, 0, ((ft_strchr(*tmpstr, '\n') - *tmpstr + 1)));
	ft_memmove(buf[fd], *tmpstr + slen(rtn_str), slen(*tmpstr) - slen(rtn_str));
	ft_bzero(&buf[fd][slen(*tmpstr) - slen(rtn_str)], 1);
	return (rtn_str);
}
