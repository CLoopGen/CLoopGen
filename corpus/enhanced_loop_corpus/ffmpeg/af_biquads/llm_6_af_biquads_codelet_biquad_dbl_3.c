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
for (i = 0; i + 1 < len; i++) {
    double temp_o2 = i2 * b2 + i1 * b1 + ibuf[i] * b0 + o2 * a2 + o1 * a1;
    double temp_i2 = ibuf[i];
    double temp_out = temp_o2 * wet + temp_i2 * dry;
    if (disabled) {
        obuf[i] = temp_i2;
    } else if (0 && temp_out < -1.) {
        (*clippings)++;
        obuf[i] = -1.;
    } else if (0 && temp_out > 1.) {
        (*clippings)++;
        obuf[i] = 1.;
    } else {
        obuf[i] = temp_out;
    }
    i++;
    double temp_o1 = i1 * b2 + temp_i2 * b1 + ibuf[i] * b0 + o1 * a2 + temp_o2 * a1;
    double temp_i1 = ibuf[i];
    temp_out = temp_o1 * wet + temp_i1 * dry;
    if (disabled) {
        obuf[i] = temp_i1;
    } else if (0 && temp_out < -1.) {
        (*clippings)++;
        obuf[i] = -1.;
    } else if (0 && temp_out > 1.) {
        (*clippings)++;
        obuf[i] = 1.;
    } else {
        obuf[i] = temp_out;
    }
    o2 = temp_o2;
    o1 = temp_o1;
    i2 = temp_i2;
    i1 = temp_i1;
}
}
