/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:30         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "score.h"

ArbResult	get_score(uint8_t *args, size_t args_len)
{
	ScoreEntry	score_entry;
	ScoreOutput	score_output;
	size_t		i;
	size_t		j;

	if (args_len != sizeof(address))
		return (ArbResult){.output = (uint8_t *)INVALID_LENGTH, .output_len = ft_strlen(INVALID_LENGTH), .status = Failure};

    ft_memcpy(score_entry.user, args, sizeof(address));

	score_output.buffer_index = 0;
	i = 0;
	while (i < MAX_USERS)
	{
		if (ft_memcmp(users[i].user, score_entry.user, sizeof(address)) == 0)
        {
			if (users[i].score_count > 0)
			{
				j = 0;
				while (j < users[i].score_count && j < MAX_SCORES)
				{
					ft_memcpy(score_output.score_buffer + score_output.buffer_index, users[i].score[j], sizeof(uint256));
					score_output.buffer_index += sizeof(uint256);
					j++;
                }
				return (ArbResult){.output = score_output.score_buffer, .output_len = score_output.buffer_index, .status = Success
				};
			}
			else
				return (ArbResult){.output = (uint8_t *)ERROR_SCORE, .output_len = ft_strlen(ERROR_SCORE), .status = Failure};
		}
        i++;
    }
	return (ArbResult){.output = (uint8_t *)ERROR_USER, .output_len = ft_strlen(ERROR_USER), .status = Failure};
}
