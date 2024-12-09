/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:25         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "score.h"

ArbResult	set_score(uint8_t *args, size_t args_len)
{
	ScoreEntry	score_entry;
	size_t		i;

	if (args_len != sizeof(address) + sizeof(uint256))
		return (ArbResult){.output = (uint8_t *)INVALID_ARGUMENT, .output_len = ft_strlen(INVALID_ARGUMENT), .status = Failure};

	ft_memcpy(score_entry.user, args, sizeof(address));
	ft_memcpy(*score_entry.score, args + sizeof(address), sizeof(uint256));
	score_entry.score_count = 1;

	i = 0;
	while (i < MAX_USERS)
	{
		if (ft_memcmp(users[i].user, score_entry.user, sizeof(address)) == 0)
		{
			if (users[i].score_count < MAX_SCORES)
			{
				ft_memcpy(users[i].score[users[i].score_count], score_entry.score[0], sizeof(uint256));
				users[i].score_count++;
				return (ArbResult){.output = (uint8_t *)SCORE_SET, .output_len = ft_strlen(SCORE_SET), .status = Success};
			}
			else
			return (ArbResult){.output = (uint8_t *)SCORE_MAX, .output_len = ft_strlen(SCORE_MAX), .status = Failure};
		}
		i++;
    }
	return (ArbResult){.output = (uint8_t *)ERROR_USER, .output_len = ft_strlen(ERROR_USER), .status = Failure};
}
