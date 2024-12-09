/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_users.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:35         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "score.h"

void	populate_ranking_array(ScoreEntry *sorted_users, size_t nbofusers)
{
	size_t i;

	i = 0;
	while (i < nbofusers)
	{
		if (sorted_users[i].score_count > 0)
			ft_memcpy(sorted_users[i].ranking[0], sorted_users[i].score[0], sizeof(uint256));
		i++;
	}
}

void	populate_output_buffer(ScoreEntry *sorted_users, ScoreOutput *score_output, size_t nbofusers)
{
	size_t i;

	score_output->buffer_index = 0;
	i = 0;
	while (i < nbofusers)
	{
		if (sorted_users[i].score_count > 0)
		{
			ft_memcpy(score_output->score_buffer + score_output->buffer_index, sorted_users[i].ranking[0], sizeof(uint256));
			score_output->buffer_index += sizeof(uint256);
		}
		i++;
	}
}

ArbResult	rank_users(uint8_t *args, size_t args_len)
{
	ScoreEntry sorted_users[MAX_USERS];
	ScoreOutput score_output;

	(void)args;
    (void)args_len;

    ft_memcpy(sorted_users, users, sizeof(users));

    sort_users(sorted_users, MAX_USERS);
	populate_ranking_array(sorted_users, MAX_USERS);
	populate_output_buffer(sorted_users, &score_output, MAX_USERS);

    return (ArbResult){.output = score_output.score_buffer, .output_len = score_output.buffer_index, .status = Success
    };
}