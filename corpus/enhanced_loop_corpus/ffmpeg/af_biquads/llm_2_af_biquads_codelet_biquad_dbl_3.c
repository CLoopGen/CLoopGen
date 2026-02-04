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
    // Variant 1: Strided memory access with stride of 2
    // This variant accesses ibuf and obuf with a fixed stride, processing elements at even indices first
    // and simulating a pattern where data is accessed non-consecutively for potential cache behavior changes.
    int stride = 2;
    int n = (len + 1) / stride; // Number of iterations to cover all relevant elements
    double temp_i1 = i1;
    double temp_i2 = i2;
    double temp_o1 = o1;
    double temp_o2 = o2;

    for (i = 0; i < n; i++) {
        int idx = i * stride;
        if (idx + 1 >= len) break;

        temp_o2 = temp_i2 * b2 + temp_i1 * b1 + ibuf[idx] * b0 + temp_o2 * a2 + temp_o1 * a1;
        temp_i2 = ibuf[idx];
        out = temp_o2 * wet + temp_i2 * dry;
        if (disabled) {
            obuf[idx] = temp_i2;
        } else if (0 && out < -1.) {
            (*clippings)++;
            obuf[idx] = -1.;
        } else if (0 && out > 1.) {
            (*clippings)++;
            obuf[idx] = 1.;
        } else {
            obuf[idx] = out;
        }

        if (idx + 1 >= len) continue;

        temp_o1 = temp_i1 * b2 + temp_i2 * b1 + ibuf[idx+1] * b0 + temp_o1 * a2 + temp_o2 * a1;
        temp_i1 = ibuf[idx+1];
        out = temp_o1 * wet + temp_i1 * dry;
        if (disabled) {
            obuf[idx+1] = temp_i1;
        } else if (0 && out < -1.) {
            (*clippings)++;
            obuf[idx+1] = -1.;
        } else if (0 && out > 1.) {
            (*clippings)++;
            obuf[idx+1] = 1.;
        } else {
            obuf[idx+1] = out;
        }
    }

    // Update global state variables after loop
    i1 = temp_i1;
    i2 = temp_i2;
    o1 = temp_o1;
    o2 = temp_o2;
}
