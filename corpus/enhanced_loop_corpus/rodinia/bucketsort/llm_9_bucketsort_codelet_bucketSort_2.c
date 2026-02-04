#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;
extern int *nullElements;
extern unsigned int *origOffsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < (1 << 9); i++) {
    uint32_t h_val = h_offsets[i];
    origOffsets[i + 1] = h_val + origOffsets[i];
    nullElements[i] = ((h_val & 3) != 0) ? ((h_val | 3) + 1 - h_val) : 0;
}
}
