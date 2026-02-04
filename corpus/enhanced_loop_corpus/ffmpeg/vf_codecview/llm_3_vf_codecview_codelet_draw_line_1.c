#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int ey;
extern int stride;
extern int color;
extern int x;
extern int y;
extern int fr;
extern int f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop order and stride-based traversal
    // This variant accesses elements in a column-stride fashion across rows, simulating transposed access pattern
    for (x = 0; x <= (ey * f) >> 16; x++) {
        for (y = 0; y <= ey; y++) {
            int computed_x = (y * f) >> 16;
            if (computed_x != x) continue; // Only process when computed x matches current x
            fr = (y * f) & 65535;
            buf[y * stride + x] += (color * (65536 - fr)) >> 16;
            if (fr)
                buf[y * stride + x + 1] += (color * fr) >> 16;
        }
    }
}
