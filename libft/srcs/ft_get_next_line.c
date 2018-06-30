/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:27:51 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/18 12:49:42 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int		ret_strlen(char *s)
{
	int		pos_ret;

	pos_ret = 0;
	while (s[pos_ret])
	{
		if (s[pos_ret] == '\n')
			return (pos_ret);
		pos_ret++;
	}
	return (-1);
}

static t_list	*init_get(t_list **lst, int fd)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp && tmp->content)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	ft_lstadd(lst, ft_lstnew("", (size_t)fd));
	tmp = *lst;
	return (tmp);
}

static int		get_str(int fd, char **line, char *tmp, t_list **lst)
{
	int		ind;
	char	*str;

	str = NULL;
	ind = 0;
	if ((ind = ret_strlen(tmp)) != -1)
	{
		str = ft_strsub(tmp, (ind + 1), (ft_strlen(tmp) - (ind + 1)));
		ft_lstadd(lst, ft_lstnew(str, (size_t)fd));
		*line = ft_strsub(tmp, 0, ind);
		free(str);
	}
	else
		*line = ft_strdup(tmp);
	if (*line == NULL)
		return (-1);
	return (1);
}

static int		test_content(const int fd, char **tmp)
{
	char	*buf;
	t_list	*l_buf;
	int		size;
	int		n;

	size = 0;
	l_buf = ft_lstnew(NULL, fd);
	buf = ft_strnew(BUFF_SIZE);
	while ((ret_strlen(buf) == -1) && (n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		ft_lstadd_last(&l_buf, ft_lstnew(buf, n));
		size = size + n;
	}
	if ((*tmp = ft_realloc(*tmp, (size))) == NULL)
		return (-1);
	while (l_buf != NULL && l_buf->content != NULL)
	{
		*tmp = ft_strncat(*tmp, l_buf->content, ft_strlen(l_buf->content));
		l_buf = ft_lst_del_one(l_buf, l_buf->content, l_buf->content_size);
	}
	free(buf);
	return (n);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*tmp;
	char			*str;
	int				n;

	if (fd < 0 || line == NULL || read(fd, 0, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	n = 0;
	str = NULL;
	tmp = init_get(&lst, fd);
	str = ft_strdup(tmp->content);
	lst = ft_lst_del_one(lst, tmp->content, fd);
	if (ret_strlen(str) == -1)
	{
		n = test_content(fd, &str);
		if ((n == 0 && str[0] == '\0') || n == -1)
			return (n);
	}
	if ((n = get_str(fd, line, str, &lst)) != 1)
		return (n);
	free(str);
	return (1);
}
