/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Readme_rank_users.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:45         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/**
 * 
 * Continuing with the Example...
 * 
 * We already have the users array populated with data. Let's assume we have two users:
 * User 1 (users[0]):
 *      user = 0x1234567890abcdef1234567890abcdef12345678
 *      Scores: 50, 75, 100
 *      score_count = 3
 * User 2 (users[1]):
 *      user = 0xabcdef1234567890abcdef1234567890abcdef12
 *      Scores: 25, 45, 60
 *      score_count = 3
 * The 'rank_users' function ensures that the user with the highest score appears first in the result, 
 * while the user with the lower score appears second.
 * 
 * Steps:
 * A.- Copy users array to sorted_users (ft_memcpy)
 * B.- Sort the users (see sort_users.c)
 *     User 1: 50
 *     User 2: 25
 * C.- Populate the ranking array for each user
 *     It will populate each user's ranking array with their highest score
 *      User 1: ranking[0] = 50
 *      User 2: ranking[0] = 25
 * D.- Populate the output buffer with the rankings
 *     It will store the rankings of all users in the 'score_output.score_buffer'
 *     score_output.score_buffer[0..31] = 50 (User 1's first score).
 *     score_output.score_buffer[32..63] = 25 (User 2's first score).
 *     score_output.buffer_index = 64
 * E.- Return the final result
 *     The function returns an ArbResult
 *     output: A buffer containing the rankings (50, 25).
 *     output_len: 64 (since the buffer has two uint256 values, each 32 bytes).
 *     status: Success.
 */
