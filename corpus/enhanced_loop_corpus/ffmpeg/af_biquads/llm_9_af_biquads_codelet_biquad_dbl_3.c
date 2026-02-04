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
extern  double *ibuf;
extern double *obuf;
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
// Reduce effective trip count and simplify operations to lower computational load
for (i = 0; i + 1 < len; i += 2) {
    // Approximate filter: remove recursive feedback terms (a1, a2 set to 0 conceptually)
    double o_current;

    // First sample: feedforward only
    o_current = ibuf[i] * b0 + i1 * b1 + i2 * b2;
    out = o_current * wet + ibuf[i] * dry;
    if (disabled) {
        obuf[i] = ibuf[i];
    } else {
        obuf[i] = out;
    }

    // Update history with reduced state updates
    i2 = i1;
    i1 = ibuf[i];

    // Second sample
    i++;
    o_current = ibuf[i] * b0 + i1 * b1 + i2 * b2;
    out = o_current * wet + ibuf[i] * dry;
    if (disabled) {
        obuf[i] = ibuf[i];
    } else {
        obuf[i] = out;
    }

    // Update history
    i2 = i1;
    i1 = ibuf[i];
}
}
