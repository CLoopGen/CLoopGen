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
    // Variant 2: Strided Memory Access via Pointer Arithmetic with Fixed Increments
    // Restructure pointer updates to use fixed increments per row/column,
    // simulating a more predictable stride pattern beneficial for vectorization.

    unsigned char *p_row = p;
    unsigned char *lum_row = lum;

    for (y = 0; y < height; y += 2) {
        unsigned char *p_ptr = p_row;
        unsigned char *lum_ptr = lum_row;

        for (x = 0; x < width; x += 2) {
            // Process 2x2 pixel block using consistent offsets from current pointer
            r = p_ptr[0]; g = p_ptr[1]; b = p_ptr[2];
            r1 = r; g1 = g; b1 = b;

            lum_ptr[0] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                          ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                          ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;

            r = p_ptr[3]; g = p_ptr[4]; b = p_ptr[5];
            r1 += r; g1 += g; b1 += b;

            lum_ptr[1] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                          ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                          ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;

            r = p_ptr[wrap3 + 0]; g = p_ptr[wrap3 + 1]; b = p_ptr[wrap3 + 2];
            r1 += r; g1 += g; b1 += b;

            lum_ptr[wrap + 0] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                                 ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                                 ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;

            r = p_ptr[wrap3 + 3]; g = p_ptr[wrap3 + 4]; b = p_ptr[wrap3 + 5];
            r1 += r; g1 += g; b1 += b;

            lum_ptr[wrap + 1] = (((int)(0.29899999999999999 * (1 << 8) + 0.5)) * r +
                                 ((int)(0.58699999999999997 * (1 << 8) + 0.5)) * g +
                                 ((int)(0.114 * (1 << 8) + 0.5)) * b + (1 << 7)) >> 8;

            cb[0] = ((-((int)(0.16874 * (1 << 8) + 0.5)) * r1 -
                      ((int)(0.33126 * (1 << 8) + 0.5)) * g1 +
                      ((int)(0.5 * (1 << 8) + 0.5)) * b1 + 511) >> 10) + 128;

            cr[0] = ((((int)(0.5 * (1 << 8) + 0.5)) * r1 -
                       ((int)(0.41869 * (1 << 8) + 0.5)) * g1 -
                       ((int)(0.08131 * (1 << 8) + 0.5)) * b1 + 511) >> 10) + 128;

            cb++;
            cr++;
            p_ptr += 6;          // Advance by 2 pixels (RGB x2)
            lum_ptr += 2;        // Advance luminance by 2
        }

        p_row += 2 * wrap3;      // Move to next two scan lines in source
        lum_row += 2 * wrap;     // Move to next two rows in lum
    }
}
