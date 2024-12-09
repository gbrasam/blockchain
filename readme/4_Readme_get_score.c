/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Readme_get_score.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:45         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/**
 * 
 * The get_score function retrieves the scores for the specified user by searching the users array for the user's address.
 * It returns the scores in a buffer with the appropriate length and status.
 * 
 * Continuing with the Example...
 * 
 * Now, the user 0x1234567890abcdef1234567890abcdef12345678 has 3 scores: 50, 75, and 100
 * 
 * Input to the get_score function:
 * 1.- uint8_t *args
 * user address -> 0x1234567890abcdef1234567890abcdef12345678
 * 2.- size_t args_len
 * 20 (since an address is 20 bytes long).
 * 
 * Steps:
 * A.- Argument Length Validation
 *     it checks if the length of args matches the expected size of an address (20 bytes)
 * B.- Copy User Address (ft_memcpy)
 *     Now, score_entry.user contains the address 0x1234567890abcdef1234567890abcdef12345678
 * C.- Initialize score_output
 *     The score_output structure is initialized, and its buffer_index is set to 0
 * D.- Search for User in users Array
 *     The function enters a loop to search through the users array for the address provided (0x1234567890abcdef1234567890abcdef12345678)
 * E.- Check if the User Has Scores
 *     Now that the user is found, the function checks if the user has any scores.
 *     The user's score_count is 3, so the condition is true and the function proceeds to retrieve the scores
 * F.- Retrieve Scores
 *     The function enters another loop to copy the scores into the score_output.score_buffer.
 *     It will copy the scores one by one until it has copied all the scores for the user.
 * G.- Return Scores
 *     The function returns an ArbResult
 *     output: The buffer containing the three scores: 50, 75, and 100 (in uint256 format, each score being 32 bytes).     
 *     output_len: The length of the buffer, which is 96 bytes (32 bytes for each of the 3 scores).
 *     status: Success.    
 */
