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
for (i = 0; i + 3 < len; i += 4) {
    for (int step = 0; step < 4; step++) {
        int idx = i + step;
        double temp_in = ibuf[idx];
        double temp_out;
        if (step % 2 == 0) {
            o2 = i2 * b2 + i1 * b1 + temp_in * b0 + o2 * a2 + o1 * a1;
            i2 = temp_in;
            temp_out = o2 * wet + i2 * dry;
            i1 = temp_in; // Update i1 for next odd step
        } else {
            o1 = i1 * b2 + i2 * b1 + temp_in * b0 + o1 * a2 + o2 * a1;
            i1 = temp_in;
            temp_out = o1 * wet + i1 * dry;
            i2 = temp_in; // Update i2 for next even step
        }
        if (disabled) {
            obuf[idx] = temp_in;
        } else if (0 && temp_out < -1.) {
            (*clippings)++;
            obuf[idx] = -1.;
        } else if (0 && temp_out > 1.) {
            (*clippings)++;
            obuf[idx] = 1.;
        } else {
            obuf[idx] = temp_out;
        }
    }
}
}
