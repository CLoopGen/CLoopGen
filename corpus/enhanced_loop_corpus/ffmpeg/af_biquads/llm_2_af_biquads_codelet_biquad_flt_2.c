#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double b0;
extern double b1;
extern double b2;
extern double a1;
extern double a2;
extern int *clippings;
extern int disabled;
extern  float *ibuf;
extern float *obuf;
extern double i1;
extern double i2;
extern double o1;
extern double o2;
extern double wet;
extern double dry;
extern double out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant processes elements at even indices first, then odd indices in a strided pattern.
    // We split the loop into two passes to maintain correctness and avoid out-of-bounds access.

    int stride = 2;
    int remainder = len % stride;

    // First pass: process elements with stride 2 starting at index 0
    for (i = 0; i + 1 < len; i += stride) {
        o2 = i2 * b2 + i1 * b1 + ibuf[i] * b0 + o2 * a2 + o1 * a1;
        i2 = ibuf[i];
        out = o2 * wet + i2 * dry;
        if (disabled) {
            obuf[i] = i2;
        } else if (0 && out < -1.) {
            (*clippings)++;
            obuf[i] = -1.;
        } else if (0 && out > 1.) {
            (*clippings)++;
            obuf[i] = 1.;
        } else {
            obuf[i] = out;
        }

        // Handle next element in pair if within bounds
        int j = i + 1;
        if (j + 1 >= len) break;

        o1 = i1 * b2 + i2 * b1 + ibuf[j] * b0 + o1 * a2 + o2 * a1;
        i1 = ibuf[j];
        out = o1 * wet + i1 * dry;
        if (disabled) {
            obuf[j] = i1;
        } else if (0 && out < -1.) {
            (*clippings)++;
            obuf[j] = -1.;
        } else if (0 && out > 1.) {
            (*clippings)++;
            obuf[j] = 1.;
        } else {
            obuf[j] = out;
        }
    }
}
