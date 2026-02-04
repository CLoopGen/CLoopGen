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
extern  int32_t *ibuf;
extern int32_t *obuf;
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
    // This variant processes elements at even indices first, then odd indices in a strided pattern
    // Effectively unrolls and reorganizes access to ibuf and obuf with step size 2
    int stride = 2;
    int remainder = len % stride;

    // Process pairs with stride
    for (i = 0; i + stride < len; i += stride) {
        // First element in stride
        o2 = i2 * b2 + i1 * b1 + ibuf[i] * b0 + o2 * a2 + o1 * a1;
        i2 = ibuf[i];
        out = o2 * wet + i2 * dry;
        if (disabled) {
            obuf[i] = i2;
        } else if (out < (-2147483647 - 1)) {
            (*clippings)++;
            obuf[i] = (-2147483647 - 1);
        } else if (out > 2147483647) {
            (*clippings)++;
            obuf[i] = 2147483647;
        } else {
            obuf[i] = out;
        }

        // Second element in stride
        o1 = i1 * b2 + i2 * b1 + ibuf[i+1] * b0 + o1 * a2 + o2 * a1;
        i1 = ibuf[i+1];
        out = o1 * wet + i1 * dry;
        if (disabled) {
            obuf[i+1] = i1;
        } else if (out < (-2147483647 - 1)) {
            (*clippings)++;
            obuf[i+1] = (-2147483647 - 1);
        } else if (out > 2147483647) {
            (*clippings)++;
            obuf[i+1] = 2147483647;
        } else {
            obuf[i+1] = out;
        }
    }

    // Handle remaining elements if any
    for (; i < len - 1; i++) {
        o2 = i2 * b2 + i1 * b1 + ibuf[i] * b0 + o2 * a2 + o1 * a1;
        i2 = ibuf[i];
        out = o2 * wet + i2 * dry;
        if (disabled) {
            obuf[i] = i2;
        } else if (out < (-2147483647 - 1)) {
            (*clippings)++;
            obuf[i] = (-2147483647 - 1);
        } else if (out > 2147483647) {
            (*clippings)++;
            obuf[i] = 2147483647;
        } else {
            obuf[i] = out;
        }
        i++;
        o1 = i1 * b2 + i2 * b1 + ibuf[i] * b0 + o1 * a2 + o2 * a1;
        i1 = ibuf[i];
        out = o1 * wet + i1 * dry;
        if (disabled) {
            obuf[i] = i1;
        } else if (out < (-2147483647 - 1)) {
            (*clippings)++;
            obuf[i] = (-2147483647 - 1);
        } else if (out > 2147483647) {
            (*clippings)++;
            obuf[i] = 2147483647;
        } else {
            obuf[i] = out;
        }
    }
}
