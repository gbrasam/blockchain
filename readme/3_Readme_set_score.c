/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Readme_set_score.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:45         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/**
 * Assumptions:
 * MAX_USERS = 5 (maximum number of users the program can track).
 * MAX_SCORES = 3 (maximum number of scores per user).
 * The users array [ScoreEntry] is populated (dummy data):
 * users[0].user = 0x1234567890abcdef1234567890abcdef12345678;
 * users[0].score[0] = 50;      // First score = 50
 * users[0].score[1] = 75;      // Second score = 75
 * users[0].score_count = 2;    // Two scores already set for this user
 * 
 * Input to the set_score function:
 * 1.- uint8_t *args
 * user address -> 0x1234567890abcdef1234567890abcdef12345678 (first 20 bytes)
 * score 100 (as a uint256) -> 0x0000000000000000000000000000000000000000000000000000000000000064 (next 32 bytes)
 * 2.- size_t args_len
 * The total length of args is 52 bytes (20 bytes for address + 32 bytes for score).
 * 
 * Steps:
 * A.- Argument Length Validation
 *     The function checks if the length of args is valid:
 *     sizeof(address) = 20 bytes.
 *     sizeof(uint256) = 32 bytes.
 *     total required length = 20 + 32 = 52 bytes.
 * B.- Copy User Address and Score (ft_memcpy)
 *     The user address (args's first 20 bytes) is copied into 'score_entry.user' -> 0x1234567890abcdef1234567890abcdef12345678
 *     The score (args's next 32 bytes) is copied into 'score_entry.score' -> 100 (the score passed in the input)
 *     The score_count is set to 1, indicating that we're adding one new 'score for this user' -> 1
 * C.- Search for the User in the users Array
 *     The function loops through the users array to find the user with the address 'score_entry.user'
 *     It compares each user's address using ft_memcmp
 * D.- Check if User Can Have More Scores
 *     The program checks if the user has room for more scores
 *     The user's current score_count is 2 (they already have two scores: 50 and 75) (see assumptions)
 *     Since score_count < MAX_SCORES (2 < 3), there is space for one more score.
 *     The new score (100) is added to the users[0].score[2] slot.
 *     The score_count for this user is incremented to 3 (users[0].score_count = 3).
 *     The function then returns a success result with the message SCORE_SET
 *     ArbResult{
 *          .output = "SCORE_SET",
 *          .output_len = strlen("SCORE_SET"),
 *          .status = Success
 *     }
 * E.- Final Result
 *     At this point, the users array looks like this:
 *     users[0].user = 0x1234567890abcdef1234567890abcdef12345678;
 *     users[0].score[0] = 50;
 *     users[0].score[1] = 75;
 *     users[0].score[2] = 100;   // Newly added score
 *     users[0].score_count = 3;  // Total 3 scores
 * F.- If now you tried to add another score, the function would return:
 *     ArbResult{
 *          .output = "SCORE_MAX",
 *          .output_len = strlen("SCORE_MAX"),
 *          .status = Failure
 *     }
 * G.- If no matching user is found in the loop (if 'score_entry.user' didn't match any of the users in the array),
 *     the function would return:
 *     ArbResult{
 *          .output = "ERROR_USER",
 *          .output_len = strlen("ERROR_USER"),
 *          .status = Failure
 *     }
 */
