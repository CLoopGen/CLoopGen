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



void loop() {
    // Variant 2: Strided Access with Fixed Step Unrolling
    // Modify memory access to use a fixed stride based on known alignment, unroll inner loop partially,
    // and simulate wider vector-friendly access patterns (even if scalar).
    // Also change indexing to base pointers plus computed indices to reduce pointer aliasing effects.

    int y_idx, x_idx;
    unsigned char *p_base;
    unsigned char *lum_base;
    unsigned char *cb_ptr = cb;
    unsigned char *cr_ptr = cr;

    for (y_idx = 0; y_idx < height; y_idx += 2) {
        p_base = &p[y_idx * wrap3];
        lum_base = &lum[y_idx * wrap];

        for (x_idx = 0; x_idx < width; x_idx += 2) {
            int offset = x_idx * 3;
            int lum_offset = x_idx;

            // First pixel (x, y)
            r = p_base[offset + 0];
            g = p_base[offset + 1];
            b = p_base[offset + 2];
            r1 = r;
            g1 = g;
            b1 = b;

            lum_base[lum_offset] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                                    ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                                    ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;

            // Second pixel (x+1, y)
            r = p_base[offset + 3];
            g = p_base[offset + 4];
            b = p_base[offset + 5];
            r1 += r;
            g1 += g;
            b1 += b;

            lum_base[lum_offset + 1] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                                        ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                                        ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;

            // First pixel (x, y+1)
            r = p_base[offset + wrap3 + 0];
            g = p_base[offset + wrap3 + 1];
            b = p_base[offset + wrap3 + 2];
            r1 += r;
            g1 += g;
            b1 += b;

            lum_base[lum_offset + wrap] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                                           ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                                           ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;

            // Second pixel (x+1, y+1)
            r = p_base[offset + wrap3 + 3];
            g = p_base[offset + wrap3 + 4];
            b = p_base[offset + wrap3 + 5];
            r1 += r;
            g1 += g;
            b1 += b;

            lum_base[lum_offset + wrap + 1] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                                               ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                                               ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;

            // Compute chroma values for 2x2 block
            cb_ptr[x_idx / 2] = ((-((int)(0.16874 * (1 << 8) + 0.5)) * r1 -
                                  ((int)(0.33126 * (1 << 8) + 0.5)) * g1 +
                                  ((int)(0.5 * (1 << 8) + 0.5)) * b1 + 511) >> 10) + 128;

            cr_ptr[x_idx / 2] = ((((int)(0.5 * (1 << 8) + 0.5)) * r1 -
                                  ((int)(0.41869 * (1 << 8) + 0.5)) * g1 -
                                  ((int)(0.08131 * (1 << 8) + 0.5)) * b1 + 511) >> 10) + 128;
        }

        cb_ptr += width / 2;
        cr_ptr += width / 2;
    }
}
