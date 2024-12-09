/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_users.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:40         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "score.h"

void	swap_highest_scores(ScoreEntry *user1, ScoreEntry *user2)
{
	uint256 temp_score;

	ft_memcpy(temp_score, user1->score[0], sizeof(uint256));
	ft_memcpy(user1->score[0], user2->score[0], sizeof(uint256));
	ft_memcpy(user2->score[0], temp_score, sizeof(uint256));
}

void	swap_score_entries(ScoreEntry *user1, ScoreEntry *user2)
{
	ScoreEntry temp_entry;

	ft_memcpy(&temp_entry, user1, sizeof(ScoreEntry));
	ft_memcpy(user1, user2, sizeof(ScoreEntry));
	ft_memcpy(user2, &temp_entry, sizeof(ScoreEntry));
}

void	sort_users(ScoreEntry *users, size_t nbofusers)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < nbofusers - 1)
	{
		j = i + 1;
		while (j < nbofusers)
		{
			if (users[i].score_count > 0 && users[j].score_count > 0)
			{
				if (ft_memcmp(users[i].score[0], users[j].score[0], sizeof(uint256)) < 0)
				{
					swap_highest_scores(&users[i], &users[j]);
					swap_score_entries(&users[i], &users[j]);
				}
			}
			j++;
		}
		i++;
	}
}
