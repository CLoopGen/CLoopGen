#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  unsigned char odd_parity[256];
extern DES_cblock *key;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access Pattern
    size_t size = sizeof(DES_cblock);
    for (i = size; i > 0; --i)
        (*key)[i - 1] = odd_parity[(*key)[i - 1]];
}
