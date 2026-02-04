#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;
extern int *nullElements;
extern unsigned int *origOffsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < (1 << 5); j++) {
    for (int i = 0; i < (1 << 5); i++) {
        int idx = (j << 5) | i;
        origOffsets[idx + 1] = h_offsets[idx] + origOffsets[idx];
        if ((h_offsets[idx] % 4) != 0) {
            nullElements[idx] = (h_offsets[idx] & ~3) + 4 - h_offsets[idx];
        } else
            nullElements[idx] = 0;
    }
}
}
