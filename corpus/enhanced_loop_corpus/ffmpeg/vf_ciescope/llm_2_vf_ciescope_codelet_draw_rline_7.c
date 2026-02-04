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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint16_t *base = &pixels[y0 * linesize + x0 * 4];
    for (;;) {
        uint16_t *pixel = base;
        pixel[0] = 65535 - pixel[0];
        pixel[1] = 65535 - pixel[1];
        pixel[2] = 65535 - pixel[2];
        pixel[3] = 65535;

        if (x0 == x1 && y0 == y1)
            break;

        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x0 += sx;
            base += 4 * sx; // Update base pointer in x direction
        }
        if (e2 < dy) {
            err += dx;
            y0 += sy;
            base += linesize * sy; // Update base pointer in y direction
        }
    }
}
