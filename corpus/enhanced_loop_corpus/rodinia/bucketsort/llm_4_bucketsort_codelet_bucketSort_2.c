#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;
extern int *nullElements;
extern unsigned int *origOffsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < (1 << 10); i++) {
        origOffsets[i + 1] = h_offsets[i] + origOffsets[i];
        nullElements[i] = ((h_offsets[i] % 4) != 0) ? ((h_offsets[i] & ~3) + 4 - h_offsets[i]) : 0;
    }
}
