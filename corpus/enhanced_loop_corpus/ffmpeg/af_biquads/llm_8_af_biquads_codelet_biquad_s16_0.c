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
for (i = 0; i + 3 < len; i += 4) {
    // Unroll loop by factor of 4 to increase computational intensity
    double temp_i[4], temp_o[4], temp_out[4];
    int idx;

    idx = i;
    o2 = i2 * b2 + i1 * b1 + ibuf[idx] * b0 + o2 * a2 + o1 * a1;
    i2 = ibuf[idx];
    temp_out[0] = o2 * wet + i2 * dry;
    temp_i[0] = i2;

    idx = i + 1;
    o1 = i1 * b2 + i2 * b1 + ibuf[idx] * b0 + o1 * a2 + o2 * a1;
    i1 = ibuf[idx];
    temp_out[1] = o1 * wet + i1 * dry;
    temp_i[1] = i1;

    idx = i + 2;
    o2 = i1 * b2 + i2 * b1 + ibuf[idx] * b0 + o2 * a2 + o1 * a1;
    i2 = ibuf[idx];
    temp_out[2] = o2 * wet + i2 * dry;
    temp_i[2] = i2;

    idx = i + 3;
    o1 = i2 * b2 + i1 * b1 + ibuf[idx] * b0 + o1 * a2 + o2 * a1;
    i1 = ibuf[idx];
    temp_out[3] = o1 * wet + i1 * dry;
    temp_i[3] = i1;

    // Apply clamping and store results
    for (int j = 0; j < 4; j++) {
        int store_idx = i + j;
        if (disabled) {
            obuf[store_idx] = temp_i[j];
        } else if (temp_out[j] < (-32768)) {
            (*clippings)++;
            obuf[store_idx] = -32768;
        } else if (temp_out[j] > 32767) {
            (*clippings)++;
            obuf[store_idx] = 32767;
        } else {
            obuf[store_idx] = (int16_t)temp_out[j];
        }
    }
}
}
