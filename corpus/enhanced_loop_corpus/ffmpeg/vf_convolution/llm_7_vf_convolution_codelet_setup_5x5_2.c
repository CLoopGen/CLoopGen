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
// Eliminate loop-carried dependencies completely and unroll partially for independent computation
#pragma unroll
for (i = 0; i < 25; i++) {
    // Break data flow by isolating each iteration entirely
    const int dx = i % 5 - 2;
    const int dy = i / 5 - 2;
    int xoff = x + dx;
    int yoff = y + dy;

    // Remove conditional data reuse; use branch-free arithmetic for clamping
    xoff = (xoff < 0) ? -xoff : xoff;
    yoff = (yoff < 0) ? -yoff : yoff;

    xoff = (xoff >= w) ? (2 * w - 1 - xoff) : xoff;
    yoff = (yoff >= h) ? (2 * h - 1 - yoff) : yoff;

    // Ensure no inter-element dependencies in c[] — all writes are independent
    // No use of c[j] where j < i, so no RAW/WAR/WAW across iterations
    uint8_t* base = src;
    int offset = xoff * bpc + yoff * stride;
    c[i] = base + offset;
}
}
