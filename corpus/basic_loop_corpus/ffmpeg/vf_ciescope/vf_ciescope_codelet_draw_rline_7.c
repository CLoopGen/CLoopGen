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
    pixels[y0 * linesize + x0 * 4 + 0] = 65535 - pixels[y0 * linesize + x0 * 4 + 0];
    pixels[y0 * linesize + x0 * 4 + 1] = 65535 - pixels[y0 * linesize + x0 * 4 + 1];
    pixels[y0 * linesize + x0 * 4 + 2] = 65535 - pixels[y0 * linesize + x0 * 4 + 2];
    pixels[y0 * linesize + x0 * 4 + 3] = 65535;
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
