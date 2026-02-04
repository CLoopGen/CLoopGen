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
extern  int16_t *ibuf;
extern int16_t *obuf;
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
    // Variant 2: Strided memory access (access every 2nd element first, then second pass)
    int stride = 2;
    // First pass: process even indices
    for (i = 0; i + 1 < len; i += stride) {
        if (i >= len) break;

        o2 = i2 * b2 + i1 * b1 + ibuf[i] * b0 + o2 * a2 + o1 * a1;
        i2 = ibuf[i];
        out = o2 * wet + i2 * dry;
        if (disabled) {
            obuf[i] = i2;
        } else if (out < (-32768)) {
            (*clippings)++;
            obuf[i] = -32768;
        } else if (out > 32767) {
            (*clippings)++;
            obuf[i] = 32767;
        } else {
            obuf[i] = (int16_t)out;
        }

        // Update state only if next index is valid
        int next_i = i + 1;
        if (next_i + 1 >= len) break;

        o1 = i1 * b2 + i2 * b1 + ibuf[next_i] * b0 + o1 * a2 + o2 * a1;
        i1 = ibuf[next_i];
        out = o1 * wet + i1 * dry;
        if (disabled) {
            obuf[next_i] = i1;
        } else if (out < (-32768)) {
            (*clippings)++;
            obuf[next_i] = -32768;
        } else if (out > 32767) {
            (*clippings)++;
            obuf[next_i] = 32767;
        } else {
            obuf[next_i] = (int16_t)out;
        }
    }
}
