/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Readme_score_h.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:45         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/**
 * 1.- fixed-size data structures
 */

/**
 * When working within the constraints of smart contracts
 * (e.g., in Solidity or EVM-compatible environments),
 * dynamic memory allocation functions like malloc are not available.
 * Instead, you rely on fixed-size data structures, mappings,
 * and efficient memory management to handle data.
*/


/**
 * 2.- type alias
 */

/**
 * The address type represents a unique 20-byte identifier for users,
 * ensuring compatibility with common blockchain address formats.
 * When you pass an address (set score) to a function 
 * you’ll handle it as a 20-byte array.
 * 1.- Store user addresses in the scores array.
 * 2.- Use these addresses as a unique key to look up or modify scores
 */

/**
 * The uint256 type represents a fixed-size 32-byte array.
 * 1.- This type is used to represent individual scores and rankings for users,
 *     ensuring precise representation of large numeric values.
 * 2.- It aligns with 256-bit integer formats commonly used in cryptographic 
 *     and blockchain-related computations, providing compatibility for such systems.
 * 3.- It functions as a raw 32-byte array, suitable for low-level operations 
 *     like memory comparison (e.g., `ft_memcmp`) and copying (e.g., `ft_memcpy`), 
 *     or for performing custom calculations and serialization.
 */


/**
 * 3.- ScoreEntry
 */

/**
 * The ScoreEntry structure represents a record for a user's scoring data.
 * It is designed to store and manage a user's unique identifier, their scores,
 * and associated rankings in a compact and efficient format.
 * It is the core data structure for tracking and managing user performance data.
 *
 * Fields:
 * 1.- 'user' (address):
 *     A 20-byte unique identifier for the user.
 *     Represent a blockchain address or user ID.
 * 2.- 'score' (uint256[MAX_SCORES]):
 *     An array of 32-byte values storing the scores for the user.
 *     The maximum number of scores is defined by MAX_SCORES.
 *     Each score is stored as a 256-bit value, accommodating
 *     very large numbers or precise calculations.
 * 3.- 'ranking' (uint256[MAX_SCORES]):
 *     An array of 32-byte values representing the user's rankings corresponding 
 *     to each score.
 *     Useful for leaderboard or competition-based systems.
 * 4.- 'score_count' (uint8_t):
 *     A single-byte counter indicating how many scores (and rankings) are currently
 *     stored for this user.
 *     This value is bounded by `MAX_SCORES`.
 */


/**
 * 4.- FunctionRegistry
 */

/**
 * The FunctionRegistry structure is a key component of the program’s mechanism for 
 * dynamically invoking different functions based on a function selector
 * (a unique identifier for each function).
 * It is essentially a registry that maps function selectors
 * (generated from the function signature ABI)
 * to their corresponding implementation.
 * Fields:
 * 1.- 'selector':
 *     This is a 32-bit unsigned integer that serves as a unique identifier for
 *     'to_function_selector' in the registry.
 *     The selector is used to determine which function to call in the registry,
 *     allowing for dynamic function invocation.
 * 2.- 'function': 
 *     This is a function pointer that points to the actual function implementation.
 *     The function takes an argument args (a byte array) and its length args_len
 *     as parameters and returns an ArbResult. 
 *     The function pointer allows the program to call the appropriate function
 *     based on the selector.
 * ABI (Application Binary Interface)
 */

/**
 * ArbResult
 * The ArbResult structure is designed to encapsulate the result of an operation
 * in the program. This is important because the functions set_score, get_score,
 * and rank_users perform computations that can either succeed or fail,
 * and they need to return both the result (e.g., a score or an error message)
 * and a status indicating whether the operation was successful.
 */


/**
 * 5.- SelectorArguments
 */

/**
 * The SelectorArguments structure is used in the call_function.
 * When you want to invoke a function from the registry,
 * you first create a SelectorArguments object.
 * This object will contain:
 * 1.- The signature of the function you want to call (set_score, get_score, or rank score).
 *     it is the unique identifier for the function to call.
 *     For example, for the function set_score(address,uint256),
 *     the signature will be a 4-byte value derived from hashing that string,
 *     used to uniquely identify that function in the registry
 * 2.- A pointer to the arguments (args) required for that function.
 * 3.- The length of the arguments (args_len).
 *     This is important because the function needs 
 *     to know how much data to expect when accessing args.
 *     It ensures that the program doesn't attempt to read beyond the available data.
 * 4.- The size of the registry (registry_size), which tells the program
 *     how many functions it needs to search through to find the correct one.
 */
