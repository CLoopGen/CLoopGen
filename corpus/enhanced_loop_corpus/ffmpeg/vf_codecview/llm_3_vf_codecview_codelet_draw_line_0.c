#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int ex;
extern int stride;
extern int color;
extern int x;
extern int y;
extern int fr;
extern int f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed indexing — treat buffer as column-major to create strided pattern across columns
    int index_y, index_y1, frac;
    for (x = 0; x <= ex; x++) {
        frac = (x * f) & 65535;
        index_y = x + ((x * f) >> 16) * stride;  // Transpose logic: access along vertical strides first
        buf[index_y] += (color * (65536 - frac)) >> 16;
        if (frac) {
            index_y1 = x + ((x * f) >> 16 + 1) * stride;
            buf[index_y1] += (color * frac) >> 16;
        }
    }
}
