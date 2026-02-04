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
    int y1, y2;
    for (y1 = 0; y1 <= ey / 2; y1++) {
        for (y2 = 0; y2 < 2; y2++) {
            y = y1 * 2 + y2;
            if (y > ey) break;
            x = (y * f) >> 16;
            fr = (y * f) & 65535;
            buf[y * stride + x] += (color * (65536 - fr)) >> 16;
            if (fr)
                buf[y * stride + x + 1] += (color * fr) >> 16;
        }
    }
}
