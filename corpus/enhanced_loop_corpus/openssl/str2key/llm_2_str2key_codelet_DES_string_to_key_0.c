#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  char *str;
extern DES_cblock *key;
extern int i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, process every second element in two passes: even and odd indices.
    // This changes the memory access pattern to strided (step of 2) while maintaining functional equivalence.
    
    register size_t len = length;
    register unsigned char j;
    
    // First pass: even indices
    for (i = 0; i < (int)len; i += 2) {
        j = str[i];
        if ((i % 16) < 8)
            (*key)[i % 8] ^= (j << 1);
        else {
            j = ((j << 4) & 240) | ((j >> 4) & 15);
            j = ((j << 2) & 204) | ((j >> 2) & 51);
            j = ((j << 1) & 170) | ((j >> 1) & 85);
            (*key)[7 - (i % 8)] ^= j;
        }
    }
    
    // Second pass: odd indices
    for (i = 1; i < (int)len; i += 2) {
        j = str[i];
        if ((i % 16) < 8)
            (*key)[i % 8] ^= (j << 1);
        else {
            j = ((j << 4) & 240) | ((j >> 4) & 15);
            j = ((j << 2) & 204) | ((j >> 2) & 51);
            j = ((j << 1) & 170) | ((j >> 1) & 85);
            (*key)[7 - (i % 8)] ^= j;
        }
    }
}
