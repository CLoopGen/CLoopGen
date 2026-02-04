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
for (i = 0; i < 4; i++) {
    for (ssize_t j = 0; j < 1; j++) {
        aes_info->decipher_key[i] = aes_info->encipher_key[i];
        aes_info->decipher_key[bytes - 4 + i] = aes_info->encipher_key[bytes - 4 + i];
    }
}
}
