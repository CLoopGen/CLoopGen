#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *restrict block;
extern  uint8_t *pixels;
extern ptrdiff_t stride;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *b = block;
    uint8_t *p = pixels;
    for (i = 0; i < 8; i++) {
        b[0] = p[0] + b[-1]; // Introduce RAW dependency: current load depends on prior store to b[-1]
        b[1] = p[1] + b[0];  // WAW and RAW: b[0] written here and used in next iteration via offset
        b[2] = p[2];
        b[3] = p[3];
        b[4] = p[4];
        b[5] = p[5];
        b[6] = p[6];
        b[7] = p[7];
        p += stride;
        b += 8;
    }
}
