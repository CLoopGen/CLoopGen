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
// Indirect memory access via precomputed offsets to decouple address calculation
static const int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
static const int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int offsets[9];

// Precompute all memory offsets using indirect addressing pattern
for (i = 0; i < 9; i++) {
    int xoff = x + dx[i];
    int yoff = y + dy[i];

    // Mirror boundaries
    if (xoff < 0) xoff = -xoff;
    else if (xoff >= w) xoff = 2 * w - 1 - xoff;

    if (yoff < 0) yoff = -yoff;
    else if (yoff >= h) yoff = 2 * h - 1 - yoff;

    offsets[i] = yoff * stride + xoff * bpc;
}

// Stride over precomputed table and assign through indirection
for (i = 0; i < 9; i++) {
    c[i] = src + offsets[i];
}
}
