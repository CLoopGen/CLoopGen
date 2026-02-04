#include <stdio.h>

#include <inttypes.h>

extern int len;
extern int i;
extern int *hit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 2; i <= len; i += 2)
        hit[i] = 0;
    // Handle odd indices if len is odd
    for (i = 1; i <= len; i += 2)
        hit[i] = 0;
}
