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
double prev_o1 = o1, prev_o2 = o2;
double prev_i1 = i1, prev_i2 = i2;

for (i = 0; i + 1 < len; i += 2) {
    int idx1 = i;
    int idx2 = i + 1;

    double new_o2 = prev_i2 * b2 + prev_i1 * b1 + ibuf[idx1] * b0 + prev_o2 * a2 + prev_o1 * a1;
    double new_i2 = ibuf[idx1];
    double out1 = new_o2 * wet + new_i2 * dry;

    double new_o1 = prev_i1 * b2 + new_i2 * b1 + ibuf[idx2] * b0 + prev_o1 * a2 + new_o2 * a1;
    double new_i1 = ibuf[idx2];
    double out2 = new_o1 * wet + new_i1 * dry;

    if (disabled) {
        obuf[idx1] = (int16_t)new_i2;
        obuf[idx2] = (int16_t)new_i1;
    } else {
        if (out1 < -32768) {
            (*clippings)++;
            obuf[idx1] = -32768;
        } else if (out1 > 32767) {
            (*clippings)++;
            obuf[idx1] = 32767;
        } else {
            obuf[idx1] = (int16_t)out1;
        }

        if (out2 < -32768) {
            (*clippings)++;
            obuf[idx2] = -32768;
        } else if (out2 > 32767) {
            (*clippings)++;
            obuf[idx2] = 32767;
        } else {
            obuf[idx2] = (int16_t)out2;
        }
    }

    prev_o2 = new_o2;
    prev_o1 = new_o1;
    prev_i2 = new_i2;
    prev_i1 = new_i1;
}

o1 = prev_o1;
o2 = prev_o2;
i1 = prev_i1;
i2 = prev_i2;
}
