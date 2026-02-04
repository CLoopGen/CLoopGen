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
for (i = 0; i < 49; i++) {
    int xi = i % 7 - 3;
    int yi = i / 7 - 3;
    int xoff = x + xi;
    int yoff = y + yi;

    // Replace conditionals with arithmetic-based reflection
    // Using sign manipulation to avoid explicit branches
    xoff = (xoff ^ ((xoff >> 31) & (xoff ^ (-xoff)))) + ((xoff >> 31) & (1));
    yoff = (yoff ^ ((yoff >> 31) & (yoff ^ (-yoff)))) + ((yoff >> 31) & (1));

    // Clamp to boundaries using arithmetic instead of conditionals
    xoff = xoff - (xoff >= w) * (2 * (xoff - w + 1));
    yoff = yoff - (yoff >= h) * (2 * (yoff - h + 1));

    c[i] = src + xoff * bpc + yoff * stride;
}
}
