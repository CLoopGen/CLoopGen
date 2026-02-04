#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t * pixels;
extern int linesize;
extern int x0;
extern int _usr_y0;
extern int x1;
extern int _usr_y1;
extern int dx;
extern int sx;
extern int dy;
extern int sy;
extern int err;
extern int e2;

// Variable name mappings to avoid conflicts with system symbols
#define y0 _usr_y0
#define y1 _usr_y1



void loop(){
    for (;;) {
        // Invert RGB components unconditionally
        uint16_t *base = &pixels[y0 * linesize + x0 * 4];
        base[0] = 65535 - base[0];
        base[1] = 65535 - base[1];
        base[2] = 65535 - base[2];
        base[3] = 65535;

        // Exit check moved earlier to reduce redundant computation
        if (x0 == x1 && y0 == y1) break;

        // Bresenham-style error update with fused control conditions
        e2 = err;
        err -= dy * (e2 > -dx);
        x0 += sx * (e2 > -dx);
        err += dx * (e2 < dy);
        y0 += sy * (e2 < dy);
    }
}
