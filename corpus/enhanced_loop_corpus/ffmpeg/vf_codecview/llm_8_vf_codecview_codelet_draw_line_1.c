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
    int y_start = 0;
    int y_step = 1;
    for (y = y_start; y <= ey; y += y_step) {
        x = (y * f + 32768) >> 16;
        fr = (y * f) & 65535;
        uint32_t color_inv = (color * (65536 - fr)) >> 16;
        uint32_t color_fr = (color * fr) >> 16;
        ptrdiff_t offset = y * stride + x;
        buf[offset] += color_inv;
        if (fr && (x + 1 < stride)) 
            buf[offset + 1] += color_fr;
    }
}
