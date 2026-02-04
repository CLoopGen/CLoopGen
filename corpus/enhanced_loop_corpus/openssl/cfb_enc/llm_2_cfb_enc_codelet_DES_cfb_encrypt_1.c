#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset applied outside the array index expression
    int base = num;
    for (i = 0; i < 8; ++i) {
        int idx = base + i;
        ovec[i] = (ovec[idx] << rem) | (ovec[idx + 1] >> (8 - rem));
    }
}
