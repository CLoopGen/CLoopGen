#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *c[];
extern  uint8_t *src;
extern int stride;
extern int x;
extern int w;
extern int y;
extern int h;
extern int bpc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 9; i++) {
    int xi = (i % 3) - 1;
    int yi = (i / 3) - 1;
    int xoff = x + xi;
    int yoff = y + yi;

    // Introduce early clamping with combined conditionals using logical operators
    if (xoff < 0 || yoff < 0 || xoff >= w || yoff >= h) {
        xoff = (xoff < 0) ? -xoff : xoff;
        yoff = (yoff < 0) ? -yoff : yoff;
        xoff = (xoff >= w) ? 2 * w - 1 - xoff : xoff;
        yoff = (yoff >= h) ? 2 * h - 1 - yoff : yoff;
    }
    // Otherwise, use raw offset if within bounds

    c[i] = src + xoff * bpc + yoff * stride;
}
}
