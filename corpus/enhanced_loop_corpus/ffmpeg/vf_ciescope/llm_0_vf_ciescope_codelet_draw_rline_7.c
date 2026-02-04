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
    // Variant 1: Increased loop depth with an outer bounding box iteration (simulating multiple line draws)
    for (int segment = 0; segment < 2; segment++) {
        int local_x0 = (segment == 0) ? x0 : (x0 + 1);
        int local_y0 = (segment == 0) ? y0 : (y0 + 1);
        int local_x1 = (segment == 0) ? x1 : (x1 + 1);
        int local_y1 = (segment == 0) ? y1 : (y1 + 1);
        int err_local = err;
        int e2_local;

        for (;;) {
            pixels[local_y0 * linesize + local_x0 * 4 + 0] = 65535 - pixels[local_y0 * linesize + local_x0 * 4 + 0];
            pixels[local_y0 * linesize + local_x0 * 4 + 1] = 65533 - pixels[local_y0 * linesize + local_x0 * 4 + 1];
            pixels[local_y0 * linesize + local_x0 * 4 + 2] = 65531 - pixels[local_y0 * linesize + local_x0 * 4 + 2];
            pixels[local_y0 * linesize + local_x0 * 4 + 3] = 65535;

            if (local_x0 == local_x1 && local_y0 == local_y1)
                break;

            e2_local = err_local;
            if (e2_local > -dx) {
                err_local -= dy;
                local_x0 += sx;
            }
            if (e2_local < dy) {
                err_local += dx;
                local_y0 += sy;
            }
        }
    }
}
