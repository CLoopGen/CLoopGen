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
    // Variant 2: Indirect access via index array (simulating irregular access pattern)
    int indices[4] = {0, 1, 2, 3};  // Relative offsets forRGBA components
    int pixel_base;
    for (;;) {
        pixel_base = y0 * linesize + x0 * 4;
        pixels[pixel_base + indices[0]] = rgbcolor[0];
        pixels[pixel_base + indices[1]] = rgbcolor[1];
        pixels[pixel_base + indices[2]] = rgbcolor[2];
        pixels[pixel_base + indices[3]] = rgbcolor[3];
        if (x0 == x1 && y0 == y1)
            break;
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y0 += sy;
        }
    }
}
