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
        int idx = y * wrap3 + x * 3;
        r = p[idx];
        g = p[idx+1];
        b = p[idx+2];
        int luma = ((int)(0.299 * (1 << 8) + 0.5)) * r + ((int)(0.587 * (1 << 8) + 0.5)) * g + ((int)(0.114 * (1 << 8) + 0.5)) * b;
        lum[y * wrap + x] = (luma + (1 << 7)) >> 8;
        if ((x & 1) == 1 && (y & 1) == 1) {
            int ox = x >> 1, oy = y >> 1;
            int sum_r = p[idx] + p[idx - 3] + p[idx - wrap3] + p[idx - wrap3 - 3];
            int sum_g = p[idx+1] + p[idx - 2] + p[idx - wrap3 + 1] + p[idx - wrap3 - 2];
            int sum_b = p[idx+2] + p[idx - 1] + p[idx - wrap3 + 2] + p[idx - wrap3 - 1];
            cb[oy * (wrap >> 1) + ox] = ((-((int)(0.16874 * (1 << 8) + 0.5)) * sum_r - ((int)(0.33126 * (1 << 8) + 0.5)) * sum_g + ((int)(0.5 * (1 << 8) + 0.5)) * sum_b + 1023) >> 10) + 128;
            cr[oy * (wrap >> 1) + ox] = ((((int)(0.5 * (1 << 8) + 0.5)) * sum_r - ((int)(0.41869 * (1 << 8) + 0.5)) * sum_g - ((int)(0.08131 * (1 << 8) + 0.5)) * sum_b + 1023) >> 10) + 128;
        }
    }
}
}
