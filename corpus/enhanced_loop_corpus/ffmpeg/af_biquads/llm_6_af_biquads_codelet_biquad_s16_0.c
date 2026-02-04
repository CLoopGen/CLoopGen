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
for (i = 0; i + 1 < len; i++) {
    double temp_o2 = i2 * b2 + i1 * b1 + ibuf[i] * b0 + o2 * a2 + o1 * a1;
    double temp_i2 = ibuf[i];
    double temp_out = temp_o2 * wet + temp_i2 * dry;
    if (!disabled) {
        if (temp_out < (-32768)) {
            (*clippings)++;
            obuf[i] = -32768;
        } else if (temp_out > 32767) {
            (*clippings)++;
            obuf[i] = 32767;
        } else {
            obuf[i] = (int16_t)temp_out;
        }
    } else {
        obuf[i] = (int16_t)temp_i2;
    }

    i++;
    double temp_o1 = i1 * b2 + temp_i2 * b1 + ibuf[i] * b0 + o1 * a2 + temp_o2 * a1;
    double temp_i1 = ibuf[i];
    double temp_out2 = temp_o1 * wet + temp_i1 * dry;

    if (!disabled) {
        if (temp_out2 < (-32768)) {
            (*clippings)++;
            obuf[i] = -32768;
        } else if (temp_out2 > 32767) {
            (*clippings)++;
            obuf[i] = 32767;
        } else {
            obuf[i] = (int16_t)temp_out2;
        }
    } else {
        obuf[i] = (int16_t)temp_i1;
    }

    o2 = temp_o2;
    o1 = temp_o1;
    i2 = temp_i2;
    i1 = temp_i1;
}
}
