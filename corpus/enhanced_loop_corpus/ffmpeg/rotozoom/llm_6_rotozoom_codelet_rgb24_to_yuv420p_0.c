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
        // Variant 1: Introduce temporary accumulators to break WAW and WAR dependencies
        // and reorganize operations to reduce immediate data reuse, increasing instruction-level parallelism.
        int r_temp[4], g_temp[4], b_temp[4];
        int lum_val[4];
        
        r_temp[0] = p[0];
        g_temp[0] = p[1];
        b_temp[0] = p[2];
        r_temp[1] = p[3];
        g_temp[1] = p[4];
        b_temp[1] = p[5];
        
        p += wrap3;
        
        r_temp[2] = p[0];
        g_temp[2] = p[1];
        b_temp[2] = p[2];
        r_temp[3] = p[3];
        g_temp[3] = p[4];
        b_temp[3] = p[5];
        
        // Compute all luminance values first to eliminate sequential dependency on 'lum' updates
        lum_val[0] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r_temp[0] +
                      ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g_temp[0] +
                      ((int)(0.114         * (1 << 8) + 0.5)) * b_temp[0] + (1 << 7)) >> 8;
        lum_val[1] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r_temp[1] +
                      ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g_temp[1] +
                      ((int)(0.114         * (1 << 8) + 0.5)) * b_temp[1] + (1 << 7)) >> 8;
        lum_val[2] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r_temp[2] +
                      ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g_temp[2] +
                      ((int)(0.114         * (1 << 8) + 0.5)) * b_temp[2] + (1 << 7)) >> 8;
        lum_val[3] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r_temp[3] +
                      ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g_temp[3] +
                      ((int)(0.114         * (1 << 8) + 0.5)) * b_temp[3] + (1 << 7)) >> 8;

        // Accumulate chroma components using full block data before writing
        int r_sum = r_temp[0] + r_temp[1] + r_temp[2] + r_temp[3];
        int g_sum = g_temp[0] + g_temp[1] + g_temp[2] + g_temp[3];
        int b_sum = b_temp[0] + b_temp[1] + b_temp[2] + b_temp[3];

        // Store luminance in raster order
        lum[0] = lum_val[0];
        lum[1] = lum_val[1];
        lum[wrap] = lum_val[2];
        lum[wrap+1] = lum_val[3];

        // Compute and store chroma downsampled values
        cb[0] = ((-((int)(0.16874 * (1 << 8) + 0.5)) * r_sum -
                  ((int)(0.33126 * (1 << 8) + 0.5)) * g_sum +
                  ((int)(0.5     * (1 << 8) + 0.5)) * b_sum +
                  4 * (1 << 7) - 1) >> (8 + 2)) + 128;
        cr[0] = ((((int)(0.5     * (1 << 8) + 0.5)) * r_sum -
                  ((int)(0.41869 * (1 << 8) + 0.5)) * g_sum -
                  ((int)(0.08131 * (1 << 8) + 0.5)) * b_sum +
                  4 * (1 << 7) - 1) >> (8 + 2)) + 128;

        // Update pointers
        cb++;
        cr++;
        p += -wrap3 + 2 * 3;
        lum += 2;
    }
    p += wrap3;
    lum += wrap;
}
}
