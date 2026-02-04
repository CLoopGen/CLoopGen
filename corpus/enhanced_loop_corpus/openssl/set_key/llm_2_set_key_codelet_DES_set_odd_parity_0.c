#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  unsigned char odd_parity[256];
extern DES_cblock *key;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every second element, forward and backward pass)
    size_t size = sizeof(DES_cblock);
    for (i = 0; i < size; i += 2)
        (*key)[i] = odd_parity[(*key)[i]];
    for (i = 1; i < size; i += 2)
        (*key)[i] = odd_parity[(*key)[i]];
}
