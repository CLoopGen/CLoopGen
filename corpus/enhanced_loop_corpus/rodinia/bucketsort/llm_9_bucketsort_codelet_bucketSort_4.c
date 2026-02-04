#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 9); i += 2) {
        unsigned int val1 = h_offsets[i];
        unsigned int val2 = h_offsets[i + 1];
        if ((val1 % 4) != 0)
            val1 = (val1 & ~3) + 4;
        if ((val2 % 4) != 0)
            val2 = (val2 & ~3) + 4;
        h_offsets[i] = val1;
        h_offsets[i + 1] = val2;
        h_offsets[i] *= 2;
        h_offsets[i + 1] *= 2;
    }
}
