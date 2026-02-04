#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  unsigned char odd_parity[256];
extern DES_cblock *key;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (sizeof(DES_cblock)) / 2; i++) {
        (*key)[i] = odd_parity[(*key)[i]];
        (*key)[i + (sizeof(DES_cblock)) / 2] = odd_parity[(*key)[i + (sizeof(DES_cblock)) / 2]];
    }
    if ((sizeof(DES_cblock)) % 2) {
        (*key)[(sizeof(DES_cblock)) - 1] = odd_parity[(*key)[(sizeof(DES_cblock)) - 1]];
    }
}
