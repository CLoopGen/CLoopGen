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
        unsigned int temp_offset = h_offsets[i];
        origOffsets[i + 1] = temp_offset + origOffsets[i];
        if ((temp_offset % 4) != 0) {
            nullElements[i] = (temp_offset & ~3) + 4 - temp_offset;
        } else {
            nullElements[i] = 0;
        }
    }
}
