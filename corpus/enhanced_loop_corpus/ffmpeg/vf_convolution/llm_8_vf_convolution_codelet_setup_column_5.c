#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int radius;
extern  uint8_t *c[];
extern  uint8_t *src;
extern int stride;
extern int x;
extern int y;
extern int h;
extern int bpc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < radius * 4 + 2; i += 2) {
        int index = x + (i / 2) - radius;
        int xoff = index >= 0 ? index : -index;
        xoff = xoff >= h ? (h > 0 ? 2 * h - 1 - xoff : 0) : xoff;
        c[i / 2] = src + y * bpc + xoff * stride;
    }
}
