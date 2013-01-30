/*
 * alg.h
 * Joseph C. Bonneau
 * April 2006
 *
 * Header file for attack algorithm, defines interface which new
 * algorithms must implement.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "encrypt.h"
#include "key_revert.h"
#include "cache_evict.h"
#include "constants.h"
#include "aes_attack.h"

#ifndef ALG_HEADER
#define ALG_HEADER

typedef struct
{
	long long total_num_timings;
	double total_time;

	double time[KEY_LENGTH][KEY_LENGTH][256];
	double time_squared[KEY_LENGTH][KEY_LENGTH][256];
	long long num_timings[KEY_LENGTH][KEY_LENGTH][256];
	double mean[KEY_LENGTH][KEY_LENGTH][256];
	double variance[KEY_LENGTH][KEY_LENGTH][256];
} timing_data;

//implemented in alg.c
int timing_sample(key_data * key, timing_pair * data);

//Attack algorithm interface
//const char * alg_name();
void init_data(timing_data * data);
void record_timing(timing_data * data, timing_pair * pair);
int check_data(timing_data * data, key_data * key);
void cache_evict();

#endif /*ALG_HEADER SEEN */

