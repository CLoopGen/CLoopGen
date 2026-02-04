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
    // Variant 2: Introduce loop-carried dependency via running average of chroma,
    // modifying data flow to carry state across iterations (WAR dependency introduced).
    static int prev_cb = 128, prev_cr = 128; // Carry forward prediction values

    for (x = 0; x < width; x += 2) {
        int r_total = 0, g_total = 0, b_total = 0;
        int lum_base;

        // Read and compute top-left pixel
        r = p[0]; g = p[1]; b = p[2];
        lum_base = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                    ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                    ((int)(0.114             * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;
        lum[0] = lum_base;
        r_total += r; g_total += g; b_total += b;

        // Read and compute top-right pixel
        r = p[3]; g = p[4]; b = p[5];
        lum[1] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                  ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                  ((int)(0.114             * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;
        r_total += r; g_total += g; b_total += b;

        p += wrap3;

        // Read and compute bottom-left pixel
        r = p[0]; g = p[1]; b = p[2];
        lum[wrap] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                     ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                     ((int)(0.114             * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;
        r_total += r; g_total += g; b_total += b;

        // Read and compute bottom-right pixel
        r = p[3]; g = p[4]; b = p[5];
        lum[wrap+1] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                       ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                       ((int)(0.114             * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;
        r_total += r; g_total += g; b_total += b;

        // Introduce dependency on previous chroma values (loop-carried WAR)
        int delta_cb = ((-((int)(0.16874 * (1 << 8) + 0.5)) * r_total -
                         ((int)(0.33126 * (1 << 8) + 0.5)) * g_total +
                         ((int)(0.5     * (1 << 8) + 0.5)) * b_total +
                         4 * (1 << 7) - 1) >> (8 + 2));
        int delta_cr = ((((int)(0.5     * (1 << 8) + 0.5)) * r_total -
                         ((int)(0.41869 * (1 << 8) + 0.5)) * g_total -
                         ((int)(0.08131 * (1 << 8) + 0.5)) * b_total +
                         4 * (1 << 7) - 1) >> (8 + 2));

        // Predictive encoding: store difference from previous block
        cb[0] = (delta_cb + prev_cb) + 128;
        cr[0] = (delta_cr + prev_cr) + 128;

        // Update predictor state (creates WAW and loop-carried dependency)
        prev_cb = delta_cb;
        prev_cr = delta_cr;

        // Pointer updates
        cb++;
        cr++;
        p += -wrap3 + 2 * 3;
        lum += 2;
    }
    p += wrap3;
    lum += wrap;
}
}
