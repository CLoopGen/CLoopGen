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
    // Variant 2: Reduced computational intensity with coalesced memory access and fewer checks per iteration
    // Combine pixel writes into a single loop over components to improve predictability

    uint16_t color_copy[4];
    color_copy[0] = rgbcolor[0]; color_copy[1] = rgbcolor[1];
    color_copy[2] = rgbcolor[2]; color_copy[3] = rgbcolor[3];

    size_t base_offset = y0 * linesize + x0 * 4;

    // Single tight loop that minimizes branching and groups work
    for (int comp = 0; ; comp++) {
        pixels[base_offset + comp] = color_copy[comp];

        if (comp == 3) {
            // End of vector write — now update Bresenham state
            if (x0 == x1 && y0 == y1) break;

            e2 = err;
            if (e2 > -dx) {
                err -= dy;
                x0 += sx;
            }
            if (e2 < dy) {
                err += dx;
                y0 += sy;
            }
            // Recompute base offset after coordinate update
            base_offset = y0 * linesize + x0 * 4;
            comp = -1; // Reset loop to 0 on next increment
        }
    }
}
