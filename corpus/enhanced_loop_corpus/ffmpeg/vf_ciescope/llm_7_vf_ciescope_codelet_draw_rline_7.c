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
    uint16_t *base_pixel;
    uint16_t val0, val1, val2;
    for (;;) {
        base_pixel = &pixels[y0 * linesize + x0 * 4];
        val0 = base_pixel[0];
        val1 = base_pixel[1];
        val2 = base_pixel[2];

        base_pixel[0] = 65535 - val0;
        base_pixel[1] = 65535 - val1;
        base_pixel[2] = 65535 - val2;
        base_pixel[3] = 65535;

        if (x0 == x1 && y0 == y1)
            break;

        e2 = err;
        // Introduce artificial WAW dependency on err via intermediate use
        int temp_err = err;
        if (e2 > -dx) {
            err = temp_err - dy;
            x0 += sx;
        }
        if (e2 < dy) {
            err = err + dx;  // Now depends on prior update to err (WAW becomes RAW)
            y0 += sy;
        }
    }
}
