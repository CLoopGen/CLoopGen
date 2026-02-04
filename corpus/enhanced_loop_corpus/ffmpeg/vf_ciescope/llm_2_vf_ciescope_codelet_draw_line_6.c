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
extern  uint16_t * rgbcolor;
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
    // Variant 1: Consecutive memory access using pointer arithmetic
    uint16_t *base = &pixels[y0 * linesize + x0 * 4];
    for (;;) {
        base[0] = rgbcolor[0];
        base[1] = rgbcolor[1];
        base[2] = rgbcolor[2];
        base[3] = rgbcolor[3];
        if (x0 == x1 && y0 == y1)
            break;
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x0 += sx;
            base += sx * 4;  // Adjust base pointer by stride in x
        }
        if (e2 < dy) {
            err += dx;
            y0 += sy;
            base += sy * linesize;  // Adjust base pointer by line stride
        }
    }
}
