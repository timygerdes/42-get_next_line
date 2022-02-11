/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:20:04 by tgerdes           #+#    #+#             */
/*   Updated: 2021/10/15 18:17:40 by tgerdes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*pchar1;
	char	*pchar2;

	i = 0;
	pchar1 = (char *)dst;
	pchar2 = (char *)src;
	if (!dst)
		return (NULL);
	if (pchar2 < pchar1)
	{
		while (len > 0)
		{
			len--;
			pchar1[len] = pchar2[len];
		}
		return (dst);
	}
	while (i < len)
	{
		pchar1[i] = pchar2[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*arr;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	s1_len = slen(s1) + 1;
	arr = malloc(sizeof(char) * s1_len);
	if (!arr)
		return (NULL);
	while (i < s1_len)
	{
		arr[i] = s1[i];
		i++;
	}
	free((void *)(s1));
	return (arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = malloc((slen(s1) + slen(s2) + 1) + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	while (i < slen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	free((void *)(s1));
	while (j < slen(s2))
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	s_len = slen(s);
	if ((size_t)start > s_len)
	{
		return (ft_strdup(""));
	}
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	while (i < (len))
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*rtn_str;
	char		*tmpstr;

	bytes_read = 1;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	rtn_str = ft_malloc(sizeof(char), 1);
	tmpstr = NULL;
	rtn_str = prepare_string(fd, bytes_read, rtn_str, &tmpstr);
	if (tmpstr)
		free(tmpstr);
	if (rtn_str == NULL)
		return (NULL);
	else
		return (rtn_str);
}
