#include <stdio.h>

#include <inttypes.h>

extern  int m;
extern  unsigned int a;
extern unsigned int x[25];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access – iterate from high to low index
    for (i = 25 - m - 1; i >= 0; i--)
        x[i] = x[i + m] ^ (x[i] >> 1) ^ ((x[i] & 1) ? a : 0);
}
