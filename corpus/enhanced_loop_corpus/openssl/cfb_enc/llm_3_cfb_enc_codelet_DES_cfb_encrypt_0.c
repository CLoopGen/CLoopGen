#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with offset base
    // Change access pattern to use a sliding window over a consecutive block
    unsigned char *base = ovec + num; // Shift base pointer to create new access pattern
    for (i = 0; i < 8; ++i)
        ovec[i] = base[i] << rem | base[i + 1] >> (8 - rem);
}
