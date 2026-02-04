#include <stdio.h>

#include <inttypes.h>

extern  int m;
extern  unsigned int a;
extern unsigned int x[25];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride of 2 (unrolling-like pattern)
    // Only process even indices to maintain safety within bounds
    for (i = 0; i < 25 - m && i < 24; i += 2)
        x[i] = x[i + m] ^ (x[i] >> 1) ^ ((x[i] & 1) ? a : 0);
}
