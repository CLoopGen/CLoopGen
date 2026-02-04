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
for (i = 0; i < 25; i++) {
    int xi = i % 5 - 2;
    int yi = i / 5 - 2;
    int xoff = x + xi;
    int yoff = y + yi;

    // Replace conditionals with sign-based reflection using bit manipulation
    xoff ^= (xoff >> 31); // Fast abs for non-negative wrap (two's complement)
    yoff ^= (yoff >> 31);
    // Clamp to boundary using arithmetic instead of branches
    xoff = w + (w - 1 - xoff);
    xoff = (xoff >= w) ? xoff - w : xoff;
    yoff = h + (h - 1 - yoff);
    yoff = (yoff >= h) ? yoff - h : yoff;

    c[i] = src + xoff * bpc + yoff * stride;
}
}
