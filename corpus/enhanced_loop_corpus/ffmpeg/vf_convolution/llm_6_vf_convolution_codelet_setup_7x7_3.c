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
    uint8_t *temp_c[49];
    for (i = 0; i < 49; i++) {
        int x_idx = i % 7;
        int y_idx = i / 7;
        int x_unclamped = x + (x_idx - 3);
        int y_unclamped = y + (y_idx - 3);
        int xoff = x_unclamped >= 0 ? x_unclamped : -x_unclamped;
        int yoff = y_unclamped >= 0 ? y_unclamped : -y_unclamped;
        xoff = xoff >= w ? 2 * w - 1 - xoff : xoff;
        yoff = yoff >= h ? 2 * h - 1 - yoff : yoff;
        temp_c[i] = src + xoff * bpc + yoff * stride;
    }
    for (i = 0; i < 49; i++) {
        c[i] = temp_c[i];
    }
}
