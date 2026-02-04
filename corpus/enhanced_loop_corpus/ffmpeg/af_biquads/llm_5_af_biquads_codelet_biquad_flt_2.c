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
for (i = 0; i + 1 < len; i++) {
    double input = ibuf[i];
    o2 = i2 * b2 + i1 * b1 + input * b0 + o2 * a2 + o1 * a1;
    i2 = input;
    out = o2 * wet + i2 * dry;

    if (!disabled && out < -1.0) {
        (*clippings)++;
        obuf[i] = -1.0f;
    } else if (!disabled && out > 1.0) {
        (*clippings)++;
        obuf[i] = 1.0f;
    } else {
        obuf[i] = (float)(disabled ? i2 : out);
    }

    i++;
    input = ibuf[i];
    o1 = i1 * b2 + i2 * b1 + input * b0 + o1 * a2 + o2 * a1;
    i1 = input;
    out = o1 * wet + i1 * dry;

    if (!disabled && out < -1.0) {
        (*clippings)++;
        obuf[i] = -1.0f;
    } else if (!disabled && out > 1.0) {
        (*clippings)++;
        obuf[i] = 1.0f;
    } else {
        obuf[i] = (float)(disabled ? i1 : out);
    }
}
}
