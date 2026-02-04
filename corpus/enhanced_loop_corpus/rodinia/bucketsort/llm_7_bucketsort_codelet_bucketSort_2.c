#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;
extern int *nullElements;
extern unsigned int *origOffsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int prev_orig = origOffsets[0];
    for (int i = 0; i < (1 << 10); i++) {
        unsigned int current_h = h_offsets[i];
        unsigned int new_orig = current_h + prev_orig;
        origOffsets[i + 1] = new_orig;
        prev_orig = new_orig;
        nullElements[i] = (current_h % 4) ? ((current_h & ~3) + 4 - current_h) : 0;
    }
}
