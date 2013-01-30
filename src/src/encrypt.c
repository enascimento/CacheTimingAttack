/*
 * encrypt.c
 * Joseph C. Bonneau
 * April 2006
 *
 * Wrapper functions around OpenSSL AES calls, also key reading from files
 */

#include "encrypt.h"
#include <stdio.h>
#include <stdlib.h>

void encrypt(unsigned char * in, unsigned char * out, key_data * key)
{
	AES_encrypt(in, out, &key->expanded);
}

void decrypt(unsigned char * in, unsigned char * out, key_data * key)
{
	AES_decrypt(in, out, &key->expanded);
}

void read_encrypt_key(key_data * key, char * key_file)
{
/*
	char open_type = 'r';

	FILE * kf = fopen(key_file, &open_type);

	if (kf == NULL)
	{
		printf("\nCouldn't open file: %s", key_file);
		exit(104);
	}
	*/

	/*
	int bread = fread(key->key_byte, 1, KEY_LENGTH, kf);

	if (bread < KEY_LENGTH)
		exit(105);

	int j;

	unsigned char temp_key[KEY_LENGTH];
	*/

	key->key_byte[0] = rand() % 256;
	key->key_byte[1] = rand() % 256;
	key->key_byte[2] = rand() % 256;
	key->key_byte[3] = rand() % 256;
	key->key_byte[4] = rand() % 256;
	key->key_byte[5] = rand() % 256;
	key->key_byte[6] = rand() % 256;
	key->key_byte[7] = rand() % 256;
	key->key_byte[8] = rand() % 256;
	key->key_byte[9] = rand() % 256;
	key->key_byte[10] = rand() % 256;
	key->key_byte[11] = rand() % 256;
	key->key_byte[12] = rand() % 256;
	key->key_byte[13] = rand() % 256;
	key->key_byte[14] = rand() % 256;
	key->key_byte[15] = rand() % 256;

	AES_set_encrypt_key(key->key_byte, 128, &key->expanded);

	//fclose(kf);
}

void read_decrypt_key(key_data * key, char * key_file)
{

	char open_type = 'r';

	FILE * kf = fopen(key_file, &open_type);

	if (kf == NULL)
	{
		printf("\nCouldn't open file: %s", key_file);
		exit(104);
	}

	int bread = fread(key->key_byte, 1, KEY_LENGTH, kf);

	if (bread < KEY_LENGTH)
		exit(105);

	int j;

	unsigned char temp_key[KEY_LENGTH];

	AES_set_decrypt_key(key->key_byte, 128, &key->expanded);

	fclose(kf);
}
