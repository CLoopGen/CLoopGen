#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef struct _StringInfo {
    char *path;
    unsigned char *datum;
    size_t length;
    size_t signature;
    char *name;
} StringInfo;

typedef struct _AESInfo {
    StringInfo *key;
    unsigned int blocksize;
    unsigned int *encipher_key;
    unsigned int *decipher_key;
    ssize_t rounds;
    time_t timestamp;
    size_t signature;
} AESInfo;

AESInfo *aes_info;
ssize_t i;
ssize_t bytes;

void init_vars() {
    bytes = 1024 * 1024; // 1MB of data (adjustable for timing ~0.01s)

    aes_info = (AESInfo *)calloc(1, sizeof(AESInfo));
    if (!aes_info) exit(1);

    aes_info->blocksize = 16;
    aes_info->rounds = 10;
    aes_info->timestamp = time(NULL);
    aes_info->signature = 0xDEADBEEF;

    aes_info->encipher_key = (unsigned int *)calloc(bytes, sizeof(unsigned int));
    aes_info->decipher_key = (unsigned int *)calloc(bytes, sizeof(unsigned int));
    if (!aes_info->encipher_key || !aes_info->decipher_key) exit(1);

    for (ssize_t j = 0; j < bytes; j++) {
        aes_info->encipher_key[j] = (unsigned int)(j * 314159 % 4096);
    }

    for (ssize_t j = 0; j < 4; j++) {
        aes_info->decipher_key[j] = 0;
        aes_info->decipher_key[bytes - 4 + j] = 0;
    }
}