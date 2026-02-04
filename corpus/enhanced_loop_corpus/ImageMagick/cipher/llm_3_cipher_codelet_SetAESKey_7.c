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
    // Variant 2: Strided memory access pattern with increasing stride to simulate non-contiguous access
    const ssize_t offsets[] = {0, 1, 2, 3};
    ssize_t base1 = 0;
    ssize_t base2 = bytes - 4;
    for (i = 0; i < 4; i += 2) {
        // Access with stride of 2, alternating between front and back segments
        aes_info->decipher_key[base1 + offsets[i]] = aes_info->encipher_key[base1 + offsets[i]];
        aes_info->decipher_key[base2 + offsets[i]] = aes_info->encipher_key[base2 + offsets[i]];
        if (i + 1 < 4) {
            aes_info->decipher_key[base1 + offsets[i + 1]] = aes_info->encipher_key[base1 + offsets[i + 1]];
            aes_info->decipher_key[base2 + offsets[i + 1]] = aes_info->encipher_key[base2 + offsets[i + 1]];
        }
    }
}
