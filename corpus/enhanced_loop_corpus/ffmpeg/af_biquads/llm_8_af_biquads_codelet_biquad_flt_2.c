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
    // Unroll loop 4 times to increase computational intensity
    double temp_o, temp_i;

    // First iteration
    o2 = i2 * b2 + i1 * b1 + ibuf[i] * b0 + o2 * a2 + o1 * a1;
    i2 = ibuf[i];
    out = o2 * wet + i2 * dry;
    if (disabled) {
        obuf[i] = i2;
    } else if (out < -1.0) {
        (*clippings)++;
        obuf[i] = -1.0f;
    } else if (out > 1.0) {
        (*clippings)++;
        obuf[i] = 1.0f;
    } else {
        obuf[i] = (float)out;
    }

    // Second iteration
    o1 = i1 * b2 + i2 * b1 + ibuf[i+1] * b0 + o1 * a2 + o2 * a1;
    i1 = ibuf[i+1];
    out = o1 * wet + i1 * dry;
    if (disabled) {
        obuf[i+1] = i1;
    } else if (out < -1.0) {
        (*clippings)++;
        obuf[i+1] = -1.0f;
    } else if (out > 1.0) {
        (*clippings)++;
        obuf[i+1] = 1.0f;
    } else {
        obuf[i+1] = (float)out;
    }

    // Third iteration
    temp_o = i2 * b2 + i1 * b1 + ibuf[i+2] * b0 + o1 * a2 + o2 * a1;
    temp_i = ibuf[i+2];
    out = temp_o * wet + temp_i * dry;
    if (disabled) {
        obuf[i+2] = temp_i;
    } else if (out < -1.0) {
        (*clippings)++;
        obuf[i+2] = -1.0f;
    } else if (out > 1.0) {
        (*clippings)++;
        obuf[i+2] = 1.0f;
    } else {
        obuf[i+2] = (float)out;
    }
    o2 = o1; o1 = temp_o;
    i2 = i1; i1 = temp_i;

    // Fourth iteration
    temp_o = i2 * b2 + i1 * b1 + ibuf[i+3] * b0 + o1 * a2 + o2 * a1;
    temp_i = ibuf[i+3];
    out = temp_o * wet + temp_i * dry;
    if (disabled) {
        obuf[i+3] = temp_i;
    } else if (out < -1.0) {
        (*clippings)++;
        obuf[i+3] = -1.0f;
    } else if (out > 1.0) {
        (*clippings)++;
        obuf[i+3] = 1.0f;
    } else {
        obuf[i+3] = (float)out;
    }
    o2 = o1; o1 = temp_o;
    i2 = i1; i1 = temp_i;
}
}
