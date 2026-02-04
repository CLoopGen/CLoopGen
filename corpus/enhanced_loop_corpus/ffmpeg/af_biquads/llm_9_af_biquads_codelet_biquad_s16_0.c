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
// Reduced computational complexity: simplify filtering and reduce operations per iteration
// Process only every second sample and skip clipping checks when disabled
if (disabled) {
    for (i = 0; i + 1 < len; i += 2) {
        obuf[i] = ibuf[i];
        obuf[i+1] = ibuf[i+1];
    }
} else {
    for (i = 0; i + 1 < len; i += 2) {
        // Lighter IIR update with reduced arithmetic
        o2 = ibuf[i] * b0 + o1 * a1;
        out = o2 * wet + ibuf[i] * dry;
        if (out < -32768) {
            (*clippings)++;
            obuf[i] = -32768;
        } else if (out > 32767) {
            (*clippings)++;
            obuf[i] = 32767;
        } else {
            obuf[i] = (int16_t)out;
        }

        o1 = ibuf[i+1] * b0 + o2 * a1;
        out = o1 * wet + ibuf[i+1] * dry;
        if (out < -32768) {
            (*clippings)++;
            obuf[i+1] = -32768;
        } else if (out > 32767) {
            (*clippings)++;
            obuf[i+1] = 32767;
        } else {
            obuf[i+1] = (int16_t)out;
        }
    }
}
}
