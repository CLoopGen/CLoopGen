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
    int temp_color_val1, temp_color_val2;
    for (y = 0; y <= ey; y++) {
        x = (y * f) >> 16;
        fr = (y * f) & 65535;
        temp_color_val1 = (color * (65536 - fr)) >> 16;
        buf[y * stride + x] += temp_color_val1;
        if (fr) {
            temp_color_val2 = (color * fr) >> 16;
            buf[y * stride + x + 1] += temp_color_val2;
        }
    }
}
