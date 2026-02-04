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
    int unroll_factor = 2;
    int remainder = (ey + 1) % unroll_factor;
    y = 0;
    for (; y <= ey - remainder; y += unroll_factor) {
        for (int uy = 0; uy < unroll_factor; uy++) {
            int local_y = y + uy;
            int local_x = (local_y * f) >> 16;
            int local_fr = (local_y * f) & 65535;
            buf[local_y * stride + local_x] += (color * (65536 - local_fr)) >> 16;
            if (local_fr)
                buf[local_y * stride + local_x + 1] += (color * local_fr) >> 16;
        }
    }
    for (; y <= ey; y++) {
        x = (y * f) >> 16;
        fr = (y * f) & 65535;
        buf[y * stride + x] += (color * (65536 - fr)) >> 16;
        if (fr)
            buf[y * stride + x + 1] += (color * fr) >> 16;
    }
}
