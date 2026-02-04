#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

typedef short IDWTELEM;

extern DWTELEM *src;
extern int stride;
extern int bias;
extern  int w;
extern  int h;
extern  int qmul;
extern int x;
extern int y;
extern int thres1;
extern int thres2;
extern IDWTELEM *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    // Inner loop unrolled by factor of 4 to increase instruction-level parallelism and computational load
    for (y = 0; y < h; y++) {
        for (x = 0; x < w - 3; x += 4) {
            int i0 = src[x + 0 + y * stride];
            int i1 = src[x + 1 + y * stride];
            int i2 = src[x + 2 + y * stride];
            int i3 = src[x + 3 + y * stride];

            // Duplicate threshold check with expanded arithmetic
            if ((unsigned int)(i0 + thres1) > thres2) {
                int sign0 = (i0 >> 31);
                int abs_i0 = (i0 ^ sign0) - sign0;
                abs_i0 <<= (7 - 4 + 8);
                abs_i0 = (abs_i0 + bias + qmul / 2) / qmul; // Add rounding
                dst[x + 0 + y * stride] = (abs_i0 ^ sign0) - sign0;
            } else {
                dst[x + 0 + y * stride] = 0;
            }

            if ((unsigned int)(i1 + thres1) > thres2) {
                int sign1 = (i1 >> 31);
                int abs_i1 = (i1 ^ sign1) - sign1;
                abs_i1 <<= (7 - 4 + 8);
                abs_i1 = (abs_i1 + bias + qmul / 2) / qmul;
                dst[x + 1 + y * stride] = (abs_i1 ^ sign1) - sign1;
            } else {
                dst[x + 1 + y * stride] = 0;
            }

            if ((unsigned int)(i2 + thres1) > thres2) {
                int sign2 = (i2 >> 31);
                int abs_i2 = (i2 ^ sign2) - sign2;
                abs_i2 <<= (7 - 4 + 8);
                abs_i2 = (abs_i2 + bias + qmul / 2) / qmul;
                dst[x + 2 + y * stride] = (abs_i2 ^ sign2) - sign2;
            } else {
                dst[x + 2 + y * stride] = 0;
            }

            if ((unsigned int)(i3 + thres1) > thres2) {
                int sign3 = (i3 >> 31);
                int abs_i3 = (i3 ^ sign3) - sign3;
                abs_i3 <<= (7 - 4 + 8);
                abs_i3 = (abs_i3 + bias + qmul / 2) / qmul;
                dst[x + 3 + y * stride] = (abs_i3 ^ sign3) - sign3;
            } else {
                dst[x + 3 + y * stride] = 0;
            }
        }
        // Handle remaining elements
        for (; x < w; x++) {
            int i = src[x + y * stride];
            if ((unsigned int)(i + thres1) > thres2) {
                if (i >= 0) {
                    i <<= (7 - 4 + 8);
                    i = (i + bias + qmul / 2) / qmul;
                    dst[x + y * stride] = i;
                } else {
                    i = -i;
                    i <<= (7 - 4 + 8);
                    i = (i + bias + qmul / 2) / qmul;
                    dst[x + y * stride] = -i;
                }
            } else
                dst[x + y * stride] = 0;
        }
    }
}
