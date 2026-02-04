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
    int trip_count = (radius + 1) * 2 + 1;
    for (i = 0; i < trip_count; i++) {
        int mirrored_i = i > radius ? 2 * radius - i : i;
        int xoff = x + mirrored_i - radius;
        xoff = xoff < 0 ? -xoff : xoff;
        xoff = xoff >= h ? 2 * h - 1 - xoff : xoff;
        if (i <= radius * 2) {
            c[i] = src + y * bpc + xoff * stride;
        }
    }
}
