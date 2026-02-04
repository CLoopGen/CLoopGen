#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *col;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; ++i) {
    if (i % 2 == 0) {
        int a0 = col[i/2] + (1 << (18 - 1)) / 8191;
        a0 *= 8191;
        col[i/2] = a0 >> 18;
    }
}
}
