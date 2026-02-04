#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;
extern int *nullElements;
extern unsigned int *origOffsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int k = 0; k < 2; k++) {
    int start = k * (1 << 9);
    int end = (k + 1) * (1 << 9);
    for (int i = start; i < end; i++) {
        origOffsets[i + 1] = h_offsets[i] + origOffsets[i];
        if ((h_offsets[i] % 4) != 0) {
            nullElements[i] = (h_offsets[i] & ~3) + 4 - h_offsets[i];
        } else
            nullElements[i] = 0;
    }
}
}
