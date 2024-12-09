/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:20         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "score.h"

uint32_t to_function_selector(const char *function_abi)
{
	uint256 result;
	native_keccak256((uint8_t *)function_abi, strlen(function_abi), result);
	return *((uint32_t *)result);
}

ArbResult	call_function(FunctionRegistry *registry, SelectorArguments *selector_args)
{
	size_t	i;

	i = 0;
	while (i < selector_args->registry_size)
	{
		if (registry[i].selector == selector_args->signature)
		{
			if (registry[i].function)
				return (registry[i].function(selector_args->args, selector_args->args_len));
			else
				return ((ArbResult){.output = NULL, .output_len = 0, .status = Failure});
		}
		i++;
	}
	return (ArbResult){.output = NULL, .output_len = 0, .status = Failure};
}

void	write_result(ArbResult call_result)
{
	if (call_result.output && call_result.output_len > 0)
	{
		if (call_result.output_len <= MAX_OUTPUT_LENGTH)
		{
			((uint8_t*)call_result.output)[call_result.output_len] = '\0';
			ft_putstr_fd((char *)call_result.output, STDOUT_FILENO);
		}
        else
			ft_putstr_fd(INVALID_OUTPUT_LENGTH, STDOUT_FILENO);
	}
	if (call_result.status == Success)
		ft_putstr_fd(STATUS_SUCCESS, STDOUT_FILENO);
	else if (call_result.status == Failure)
		ft_putstr_fd(STATUS_FAILURE, STDOUT_FILENO);
	else
		ft_putstr_fd(STATUS_UNKNOWN, STDOUT_FILENO);
}

void	set_selector_args(uint8_t *argv, size_t argc, SelectorArguments *selector_args, size_t registry_size)
{
	selector_args->registry_size = registry_size;
	selector_args->signature = *((uint32_t *)argv);
	if (selector_args->signature == to_function_selector("rank_users()"))
	{
		selector_args->args = NULL;
		selector_args->args_len = 0;
	}
	else
	{
		selector_args->args = argv + SIGNATURE_SIZE;
		selector_args->args_len = argc - SIGNATURE_SIZE;
	}
}

ScoreEntry users[MAX_USERS] = {0};

int	handler(size_t argc)
{
	uint8_t				argv[argc];
	size_t				registry_size;
	SelectorArguments	selector_args;
	ArbResult			call_result;

	if (argc == 0)
		return (Failure);
	read_args(argv);
	FunctionRegistry registry[]	= {
		{to_function_selector("set_score(address,uint256)"), set_score},
		{to_function_selector("get_score(address)"), get_score},
		{to_function_selector("rank_users()"), rank_users},
		// add more functions as needed here
	};
	registry_size = sizeof(registry) / sizeof(registry[0]);
	set_selector_args(argv, argc, &selector_args, registry_size);
	call_result = call_function(registry, &selector_args);
	write_result(call_result);
	return (call_result.status);
}
