/*
 * aes_attack.h
 * Joseph C. Bonneau
 * April 2006
 *
 * Header file for main attack class
 */

#ifndef AES_ATTACK_H
#define AES_ATTACK_H
//#define BUF_SIZE 0x100000
#define BUF_SIZE 0x10

typedef struct
{
	double time;
	unsigned char value[KEY_LENGTH];
} timing_pair;

unsigned char zero[16];

#endif

