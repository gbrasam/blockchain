/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Readme_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:45         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/**
 * 
 * The function 'int handler(size_t argc)' can be considered the main function for handling function calls and processing the input.
 * It acts as the core entry point that receives the arguments and then interacts with the rest of the system to execute specific functions based on the input.
 * 1.- The function accepts a single parameter, argc, which represents the number of arguments passed to the program or function handler.
 * 2.- Inside the function, the argument data is managed through a uint8_t argv[argc] array, which holds the raw input data (the function selector and arguments).
 * 
 * Using an example to illustrate how the different parts interact.
 * 
 * ScoreEntry users[MAX_USERS] = {0}; -> This initializes the users array to hold a maximum of MAX_USERS users.
 * Each user will have:
 *                      a user field (representing their address),
 *                      a score field (for storing their scores),
 *                      and a score_count field (for counting how many scores they've entered).
 * 
 * Imagine that the program is receiving a function call to 'set a score' for a user.
 * 
 * A.- Input:
 * 
 *     Function to call: set_score(address, uint256)
 *     Arguments for this function: A user address (0x123...abc) and a score (5).
 * 
 * B.- read_args(argv) -> it populates the argv array with data.
 * 
 * C.- FunctionRegistry registry[]
 * 
 *     C.1.- to_function_selector:  It generates the selector
 *                                  a.- 'native_keccak256' function hashes 'set_score(address,uint256)'
 *                                      -> something like 0xabcdef1234567890...
 *                                  b.- then 'to_function_selector' takes the first 4 bytes
 *                                      -> 0xabcdef12
 *
 *     C.2.- set_selector_args:     a.- Extracts the selector (0xabcdef12) from the first 4 bytes of argv(*)
 *                                      and stores it in selector_args->signature
 *                                  b.- If the signature matches rank_users(), it sets args to NULL
 *                                      because the function doesn't take any arguments.
 *                                      For other functions, it sets args to point to the data
 *                                      after the function selector and sets the appropriate args_len.
 *                                 
 *                                 (*) it would be like argv [function_selector | user_address | score]
 *                                     after calling set_selector_args
 *                                     ->signature = function_selector for set_score(address, uint256)
 *                                     ->args will point to the user address and score.
 * 
 *     C.3.- call_function:         Now that we have the selector_args (which includes the function selector and arguments),
 *                                  we pass it to the call_function function. This function searches the function registry
 *                                  to find the function that corresponds to the signature.
 *                                  a.- FunctionRegistry registry[] contains the list of registered functions,
 *                                      each associated with a selector and a function pointer.
 *                                  b.- The function 'call_function' loops through the 'registry[]'
 *                                      and checks if any of the registered functions' selectors match the selector_args->signature
 *                                  c.- If a match is found, it calls the associated function (set_score, get_score, or rank_users),
 *                                      passing the arguments stored in selector_args->args
 * 
 *     C.4.- write_result:          After the associated function (set_score, get_score, or rank_users) is called,
 *                                  it returns an ArbResult structure containing the result of the function.
 *                                  The write_result function takes this result and prints it to standard output (stdout).
 */
