/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 17:34:13 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/07/16 18:04:03 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**str_malloc_count(char *str, char check)
{
	char	**words;
	int		state;
	int		count;
	int		loop;

	state = 0;
	count = 0;
	loop = 0;
	while (str[loop] != 0)
	{
		if (str[loop] == check)
			state = 0;
		else
		{
			if (state == 0)
				count++;
			state = 1;
		}
		loop++;
	}
	printf("malloc CNT[%d]\n", count + 1);
	words = (char**)ft_calloc(sizeof(char *), count + 1);
	return (words);
}

char	*str_rangecopy(char *str, char check, size_t start)
{
	char	*dest;
	size_t	len;
	size_t	loop;

	printf("CP");
	len = start;
	while (str[len] != check)
		len++;
	dest = (char *)ft_calloc(sizeof(char), (len - start + 1));
	if (dest == 0)
		return (0);
	loop = 0;
	while (loop + start < len)
	{
		dest[loop] = str[start + loop];
		loop++;
	}
	dest[loop] = 0;
	printf("-FF\n");
	return (dest);
}

void	fill_words(char **words, char *str, char check)
{
	int		len;
	int		state;
	int		loop;

	len = 0;
	state = 0;
	loop = 0;
	while (str[len] != 0)
	{
		printf("len[%d], state[%d], cnt[%d]\n",len, state, loop);
		if (str[len] == check)
			state = 0;
		else if (state == 0)
		{
			words[loop] = str_rangecopy(str, check, len);
			state = 1;
			loop++;
		}
		len++;
	}
	loop++;
	words[loop] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		loop;

	printf("STR = [%s]\n", s);
	if (s == 0)
	{
		printf("STR is NULL\n");
		return (0);
	}
	words = str_malloc_count((char*)s, c);
	if (words == 0)
	{
		printf("SPLIT WORD ALLOC FAIL\n");
		return (0);
	}
	printf("START\n");
	fill_words(words, (char*)s, c);
	loop = 0;
	while(words[loop] != 0)
	{
		printf("STR[%d][%s]", loop, words[loop]);
		loop++;
	}
	return (words);
}
