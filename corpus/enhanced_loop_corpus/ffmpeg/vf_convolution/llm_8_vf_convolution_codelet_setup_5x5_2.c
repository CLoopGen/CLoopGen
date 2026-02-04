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
for (i = 0; i < 25; i += 2) {
    int xi = i % 5 - 2;
    int yi = i / 5 - 2;
    int xoff = x + xi;
    int yoff = y + yi;

    if (xoff < 0) xoff = -xoff;
    if (yoff < 0) yoff = -yoff;
    if (xoff >= w) xoff = 2 * w - 1 - xoff;
    if (yoff >= h) yoff = 2 * h - 1 - yoff;

    c[i] = src + xoff * bpc + yoff * stride;
    if (i + 1 < 25) {
        int next_xoff = x + ((i + 1) % 5 - 2);
        int next_yoff = y + ( (i + 1) / 5 - 2 );
        if (next_xoff < 0) next_xoff = -next_xoff;
        if (next_yoff < 0) next_yoff = -next_yoff;
        if (next_xoff >= w) next_xoff = 2 * w - 1 - next_xoff;
        if (next_yoff >= h) next_yoff = 2 * h - 1 - next_yoff;
        c[i + 1] = src + next_xoff * bpc + next_yoff * stride;
    }
}
}
