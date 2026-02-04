#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int attacks[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, handle bounds)
    for (i = 2; i < 8 + 1; i += 2)
        if (attacks[i] && attacks[i - 2])
            attacks[i] = 0;
}
