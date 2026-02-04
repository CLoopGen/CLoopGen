#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *col;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_offset = 0;
    for (i = 0; i < 8; ++i) {
        int offset = (i > 0) ? col[i-1] : 0;
        int adjusted_val = col[i] + offset + prev_offset;
        int a0 = adjusted_val + (1 << (20 - 1)) / 16383;
        a0 *= 16383;
        col[i] = (a0 >> 20) - prev_offset;
        prev_offset = col[i];
    }
}
