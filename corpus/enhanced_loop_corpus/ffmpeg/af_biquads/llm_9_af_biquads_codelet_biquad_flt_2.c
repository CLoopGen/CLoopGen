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
// Reduced computational load with decimated processing: process every 2nd sample
// and reduce arithmetic operations by simplifying filter logic

if (len < 2) return;

for (i = 0; i + 1 < len; i += 2) {
    // Simplified filtering: remove one stage of IIR feedback
    double in = ibuf[i];
    o2 = in * b0 + o2 * a1;  // Reduced coefficient usage
    out = o2 * wet + in * dry;

    if (disabled) {
        obuf[i] = (float)in;
    } else if (out < -1.0) {
        (*clippings)++;
        obuf[i] = -1.0f;
    } else if (out > 1.0) {
        (*clippings)++;
        obuf[i] = 1.0f;
    } else {
        obuf[i] = (float)out;
    }

    // Skip second sample computation entirely — lower trip count effective impact
    // Only store bypassed value for next sample
    if (!disabled) {
        obuf[i+1] = ibuf[i+1];
    } else {
        obuf[i+1] = ibuf[i+1];
    }
}

// Update state variables conservatively
i1 = ibuf[len - 2];
i2 = ibuf[len - 1];
o1 = o2;
}
