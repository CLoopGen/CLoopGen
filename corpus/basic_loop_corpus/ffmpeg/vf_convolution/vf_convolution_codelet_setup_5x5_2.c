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
    int xoff = ((x + ((i % 5) - 2)) >= 0 ? (x + ((i % 5) - 2)) : (-(x + ((i % 5) - 2))));
    int yoff = ((y + (i / 5) - 2) >= 0 ? (y + (i / 5) - 2) : (-(y + (i / 5) - 2)));
    xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
    yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
    c[i] = src + xoff * bpc + yoff * stride;
}

}
