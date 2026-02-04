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
    int prev_x = 0, delta_x;
    for (y = 0; y <= ey; y++) {
        x = (y * f) >> 16;
        delta_x = x - prev_x;
        fr = (y * f) & 65535;
        if (y > 0 && delta_x == 0) {
            buf[y * stride + x] += buf[(y-1) * stride + x] >> 8;
        } else {
            buf[y * stride + x] += (color * (65536 - fr)) >> 16;
        }
        if (fr)
            buf[y * stride + x + 1] += (color * fr) >> 16;
        prev_x = x;
    }
}
