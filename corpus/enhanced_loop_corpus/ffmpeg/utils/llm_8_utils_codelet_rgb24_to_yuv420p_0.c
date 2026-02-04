#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *lum;
extern unsigned char *cb;
extern unsigned char *cr;
extern int width;
extern int height;
extern int wrap;
extern int wrap3;
extern int x;
extern int y;
extern int r;
extern int g;
extern int b;
extern int r1;
extern int g1;
extern int b1;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x += 2) {
        // Eliminate some loop-carried dependencies by using local accumulators with delayed write-back
        int local_r = 0, local_g = 0, local_b = 0;

        r = p[0]; g = p[1]; b = p[2];
        local_r += r; local_g += g; local_b += b;
        lum[0] = (77*r + 150*g + 29*b + 128) >> 8;

        r = p[3]; g = p[4]; b = p[5];
        local_r += r; local_g += g; local_b += b;
        lum[1] = (77*r + 150*g + 29*b + 128) >> 8;

        p += wrap3; lum += wrap;

        r = p[0]; g = p[1]; b = p[2];
        local_r += r; local_g += g; local_b += b;
        lum[0] = (77*r + 150*g + 29*b + 128) >> 8;

        r = p[3]; g = p[4]; b = p[5];
        local_r += r; local_g += g; local_b += b;
        lum[1] = (77*r + 150*g + 29*b + 128) >> 8;

        // Remove RAW dependency on prior r1/g1/b1 by computing directly from local_r etc.
        // No reliance on externally defined r1/g1 state
        cb[0] = (-43*local_r - 84*local_g + 128*local_b + 511) >> 10;
        cr[0] = (128*local_r - 107*local_g - 21*local_b + 511) >> 10;

        // Clamp and shift to correct range
        cb[0] = (cb[0] + 128) & 0xFF;
        cr[0] = (cr[0] + 128) & 0xFF;

        cb++; cr++;
        p += -wrap3 + 6;
        lum += -wrap + 2;
    }
    p += wrap3;
    lum += wrap;
}
}
