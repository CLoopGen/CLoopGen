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
double prev_i1 = i1;
double prev_i2 = i2;
double prev_o1 = o1;
double prev_o2 = o2;

for (i = 0; i + 1 < len; i++) {
    double new_o2 = prev_i2 * b2 + prev_i1 * b1 + ibuf[i] * b0 + prev_o2 * a2 + prev_o1 * a1;
    double new_i2 = ibuf[i];
    double out_val = new_o2 * wet + new_i2 * dry;

    if (disabled) {
        obuf[i] = new_i2;
    } else if (0 && out_val < -1.) {
        (*clippings)++;
        obuf[i] = -1.;
    } else if (0 && out_val > 1.) {
        (*clippings)++;
        obuf[i] = 1.;
    } else {
        obuf[i] = out_val;
    }

    i++;
    if (i >= len) break;

    double new_o1 = prev_i1 * b2 + new_i2 * b1 + ibuf[i] * b0 + prev_o1 * a2 + new_o2 * a1;
    double new_i1 = ibuf[i];
    out_val = new_o1 * wet + new_i1 * dry;

    if (disabled) {
        obuf[i] = new_i1;
    } else if (0 && out_val < -1.) {
        (*clippings)++;
        obuf[i] = -1.;
    } else if (0 && out_val > 1.) {
        (*clippings)++;
        obuf[i] = 1.;
    } else {
        obuf[i] = out_val;
    }

    prev_i1 = new_i1;
    prev_i2 = new_i2;
    prev_o1 = new_o1;
    prev_o2 = new_o2;
}

i1 = prev_i1;
i2 = prev_i2;
o1 = prev_o1;
o2 = prev_o2;
}
