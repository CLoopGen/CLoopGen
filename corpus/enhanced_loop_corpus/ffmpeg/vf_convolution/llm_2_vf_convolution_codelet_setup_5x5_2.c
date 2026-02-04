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
    int x_idx = i % 5;
    int y_idx = i / 5;
    int xoff = (x + x_idx - 2);
    int yoff = (y + y_idx - 2);

    // Reflective boundary handling using absolute value and wrap-around logic
    xoff = (xoff < 0) ? -xoff : xoff;
    yoff = (yoff < 0) ? -yoff : yoff;
    xoff = (xoff >= w) ? 2 * w - 1 - xoff : xoff;
    yoff = (yoff >= h) ? 2 * h - 1 - yoff : yoff;

    // Consecutive memory access pattern: reorder computation to promote spatial locality
    // Access c[] in increasing order, but compute offsets using precomputed strides
    c[i] = src + (yoff * stride + xoff * bpc);
}
}
