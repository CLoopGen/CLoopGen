#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned int *key;
extern unsigned int *plaintext;
extern  unsigned char *p;
extern unsigned int i;
extern unsigned int j;
extern unsigned int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reversed key indexing
    for (i = 0; i < 4; i++) {
        value = 0;
        for (j = 0; j < 4; j++)
            value |= ((unsigned int)*(p + j * 2) << (8 * j));  // Strided access: every 2nd byte
        p += 8;  // Advance pointer by stride to maintain correct position for next iteration
        plaintext[i] = key[3 - i] ^ value;  // Reverse key access order
    }
}
