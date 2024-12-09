/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:15         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCORING_H
# define SCORING_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stddef.h>
# include <string.h>

# define MAX_USERS				100
# define MAX_SCORES				10
# define MAX_OUTPUT_LENGTH		1024

# define INVALID_ARGUMENT		"invalid arguments\n"
# define INVALID_LENGTH			"invalid argument length\n"
# define INVALID_OUTPUT_LENGTH	"output too large to display\n"
# define SCORE_MAX				"max scores reached\n"
# define SCORE_SET				"score set successfully\n"
# define ERROR_USER				"user not found\n"
# define ERROR_SCORE			"no scores available\n"
# define STATUS_SUCCESS			"operation was successful\n"
# define STATUS_FAILURE			"operation failed\n"
# define STATUS_UNKNOWN			"unknown status\n"

# define SIGNATURE_SIZE sizeof(uint32_t)

typedef uint8_t address[20];
typedef uint8_t uint256[32];

typedef struct
{
	address		user;
    uint256		score[MAX_SCORES];
	uint256		ranking[MAX_SCORES];
	uint8_t		score_count;
}	ScoreEntry;

extern ScoreEntry users[MAX_USERS];

typedef struct
{
    uint8_t		score_buffer[MAX_SCORES * sizeof(uint256)];
    size_t		buffer_size;
	size_t		buffer_index;
}	ScoreOutput;

typedef struct
{
	uint8_t		*output;
	size_t		output_len;
	int			status;
}	ArbResult;

typedef struct
{
	uint32_t	selector;
	ArbResult	(*function)(uint8_t *args, size_t args_len);
}	FunctionRegistry;

typedef struct
{
	size_t		registry_size;
	uint32_t	signature;
	uint8_t		*args;
	size_t		args_len;
}	SelectorArguments;

typedef enum ArbStatus
{
	Success,
	Failure,
}	ArbStatus;

/*
main.c
*/

void		read_args(const uint8_t * data);
void		native_keccak256(const uint8_t * bytes, size_t len, uint8_t * output);
uint32_t	to_function_selector(const char *function_abi);
ArbResult	call_function(FunctionRegistry *registry, SelectorArguments *selector_args);
void		write_result(ArbResult call_result);
void		set_selector_args(uint8_t *argv, size_t argc, SelectorArguments *selector_args, size_t registry_size);
int			handler(size_t argc);

/*
set_score.c
*/

ArbResult	set_score(uint8_t *args, size_t args_len);

/*
get_score.c
*/

ArbResult	get_score(uint8_t *args, size_t args_len);

/*
rank_users.c
*/

void		populate_output_buffer(ScoreEntry *sorted_users, ScoreOutput *score_output, size_t nbofusers);
void		populate_ranking_array(ScoreEntry *sorted_users, size_t nbofusers);
ArbResult	rank_users(uint8_t *args, size_t args_len);

/*
sort_users.c
*/

void		swap_highest_scores(ScoreEntry *user1, ScoreEntry *user2);
void		swap_score_entries(ScoreEntry *user1, ScoreEntry *user2);
void		sort_users(ScoreEntry *users, size_t nbofusers);

/*
utils.c
*/

void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);

#endif
