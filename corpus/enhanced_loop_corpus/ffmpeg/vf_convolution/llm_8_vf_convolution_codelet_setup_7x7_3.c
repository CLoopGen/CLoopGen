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
    int dx = i % 5 - 2;
    int dy = i / 5 - 2;
    int xoff = (x + dx) >= 0 ? (x + dx) : -(x + dx);
    int yoff = (y + dy) >= 0 ? (y + dy) : -(y + dy);
    xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
    yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
    c[i] = src + xoff * bpc + yoff * stride;
}
}
