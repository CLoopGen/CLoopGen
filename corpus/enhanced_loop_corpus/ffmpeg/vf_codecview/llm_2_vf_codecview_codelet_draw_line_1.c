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
    // Variant 1: Consecutive memory access using pointer arithmetic to improve cache locality
    uint8_t *ptr = buf;
    for (y = 0; y <= ey; y++) {
        x = (y * f) >> 16;
        fr = (y * f) & 65535;
        int offset = y * stride + x;
        ptr = buf + offset;
        *ptr += (color * (65536 - fr)) >> 16;
        if (fr && (offset + 1) < (y + 1) * stride) // Ensure we don't cross row boundary
            *(ptr + 1) += (color * fr) >> 16;
    }
}
