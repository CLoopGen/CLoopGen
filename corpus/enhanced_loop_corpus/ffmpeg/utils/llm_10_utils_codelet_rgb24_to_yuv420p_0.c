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
for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
        r = p[0];
        g = p[1];
        b = p[2];

        // Simplified luminance calculation with reduced arithmetic
        lum[0] = (77 * r + 150 * g + 29 * b + 128) >> 8;

        // Downsample chroma only at even pixel locations
        if ((x & 1) == 0 && (y & 1) == 0) {
            cb[0] = (-43 * r - 85 * g + 128 * b + 512) >> 10;
            cr[0] = (128 * r - 107 * g - 21 * b + 512) >> 10;
            cb++;
            cr++;
        }

        p += 3;
        lum++;
    }
    p += wrap3 - width * 3;
    lum += wrap - width;
}
}
