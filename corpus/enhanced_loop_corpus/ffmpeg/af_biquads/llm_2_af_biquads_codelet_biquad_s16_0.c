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
    // Variant 1: Consecutive memory access with unrolling and forward traversal
    for (i = 0; i + 1 < len; i += 2) {
        double temp_i = ibuf[i];
        o2 = i2 * b2 + i1 * b1 + temp_i * b0 + o2 * a2 + o1 * a1;
        i2 = temp_i;
        out = o2 * wet + i2 * dry;
        if (disabled) {
            obuf[i] = i2;
        } else if (out < (-32768)) {
            (*clippings)++;
            obuf[i] = -32768;
        } else if (out > 32767) {
            (*clippings)++;
            obuf[i] = 32767;
        } else {
            obuf[i] = (int16_t)out;
        }

        double temp_i_next = ibuf[i + 1];
        o1 = i1 * b2 + i2 * b1 + temp_i_next * b0 + o1 * a2 + o2 * a1;
        i1 = temp_i_next;
        out = o1 * wet + i1 * dry;
        if (disabled) {
            obuf[i + 1] = i1;
        } else if (out < (-32768)) {
            (*clippings)++;
            obuf[i + 1] = -32768;
        } else if (out > 32767) {
            (*clippings)++;
            obuf[i + 1] = 32767;
        } else {
            obuf[i + 1] = (int16_t)out;
        }
    }
}
