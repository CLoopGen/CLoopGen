#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  unsigned char odd_parity[256];
extern DES_cblock *key;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char prev = 0;
    for (i = 0; i < (sizeof(DES_cblock)); i++) {
        unsigned char current = (*key)[i];
        (*key)[i] = odd_parity[current ^ prev];
        prev = current;
    }
}
