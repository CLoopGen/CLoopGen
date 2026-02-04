#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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

extern AESInfo *aes_info;
extern ssize_t i;
extern ssize_t bytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t j;
    for (j = 0; j < 4; j++) {
        size_t idx1 = j;
        size_t idx2 = bytes - 4 + j;
        aes_info->decipher_key[idx1] = aes_info->encipher_key[idx1];
        aes_info->decipher_key[idx2] = aes_info->encipher_key[idx2];
    }
}
