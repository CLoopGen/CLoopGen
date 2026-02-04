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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of updating pointers with wrap/wrap3, precompute base offsets and access memory consecutively.
    // This improves cache locality by reducing pointer arithmetic complexity and enabling better prefetching.

    int lum_offset = 0;
    int p_offset = 0;
    int cb_offset = 0;
    int cr_offset = 0;

    for (y = 0; y < height; y += 2) {
        for (x = 0; x < width; x += 2) {
            // Load 4 pixels in row-major order using flat indexing
            int p0 = p[p_offset + 0];
            int p1 = p[p_offset + 1];
            int p2 = p[p_offset + 2];
            int p3 = p[p_offset + 3];
            int p4 = p[p_offset + 4];
            int p5 = p[p_offset + 5];
            int p6 = p[p_offset + wrap3 + 0];
            int p7 = p[p_offset + wrap3 + 1];
            int p8 = p[p_offset + wrap3 + 2];
            int p9 = p[p_offset + wrap3 + 3];
            int p10 = p[p_offset + wrap3 + 4];
            int p11 = p[p_offset + wrap3 + 5];

            // Compute luminance values directly
            lum[lum_offset + 0] = (((int)(0.299 * (1 << 8) + 0.5)) * p0 + ((int)(0.587 * (1 << 8) + 0.5)) * p1 + ((int)(0.114 * (1 << 8) + 0.5)) * p2 + (1 << 7)) >> 8;
            lum[lum_offset + 1] = (((int)(0.299 * (1 << 8) + 0.5)) * p3 + ((int)(0.587 * (1 << 8) + 0.5)) * p4 + ((int)(0.114 * (1 << 8) + 0.5)) * p5 + (1 << 7)) >> 8;
            lum[lum_offset + wrap + 0] = (((int)(0.299 * (1 << 8) + 0.5)) * p6 + ((int)(0.587 * (1 << 8) + 0.5)) * p7 + ((int)(0.114 * (1 << 8) + 0.5)) * p8 + (1 << 7)) >> 8;
            lum[lum_offset + wrap + 1] = (((int)(0.299 * (1 << 8) + 0.5)) * p9 + ((int)(0.587 * (1 << 8) + 0.5)) * p10 + ((int)(0.114 * (1 << 8) + 0.5)) * p11 + (1 << 7)) >> 8;

            // Accumulate chroma components from 2x2 block
            int r1 = p0 + p3 + p6 + p9;
            int g1 = p1 + p4 + p7 + p10;
            int b1 = p2 + p5 + p8 + p11;

            cb[cb_offset] = ((-((int)(0.16874 * (1 << 8) + 0.5)) * r1 - ((int)(0.33126 * (1 << 8) + 0.5)) * g1 + ((int)(0.5 * (1 << 8) + 0.5)) * b1 + 511) >> 10) + 128;
            cr[cr_offset] = ((((int)(0.5 * (1 << 8) + 0.5)) * r1 - ((int)(0.41869 * (1 << 8) + 0.5)) * g1 - ((int)(0.08131 * (1 << 8) + 0.5)) * b1 + 511) >> 10) + 128;

            // Update offsets for next 2x2 block
            p_offset += 6;
            lum_offset += 2;
            cb_offset += 1;
            cr_offset += 1;
        }
        p_offset += wrap3 - 2 * 3 * (width / 2);
        lum_offset += wrap - 2 * (width / 2);
    }
}
