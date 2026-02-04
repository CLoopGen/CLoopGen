#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

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
ssize_t n;
unsigned char *datum;

void init_vars() {
    n = 64 * 1024 * 1024 / 4;  // Process ~64MB of input data (each uint uses 4 bytes)

    datum = (unsigned char *)malloc(n * 4);
    if (!datum) exit(1);

    aes_info = (AESInfo *)malloc(sizeof(AESInfo));
    if (!aes_info) exit(1);

    aes_info->encipher_key = (unsigned int *)malloc(n * sizeof(unsigned int));
    if (!aes_info->encipher_key) exit(1);

    aes_info->decipher_key = NULL;
    aes_info->blocksize = 16;
    aes_info->rounds = 10;
    aes_info->timestamp = time(NULL);
    aes_info->signature = 0xDEADBEEF;

    aes_info->key = (StringInfo *)malloc(sizeof(StringInfo));
    if (!aes_info->key) exit(1);

    aes_info->key->path = NULL;
    aes_info->key->datum = NULL;
    aes_info->key->length = 0;
    aes_info->key->signature = 0;
    aes_info->key->name = NULL;

    for (ssize_t j = 0; j < n * 4; j++) {
        datum[j] = (unsigned char)(j & 0xFF);
    }

    for (ssize_t j = 0; j < n; j++) {
        aes_info->encipher_key[j] = 0;
    }
}