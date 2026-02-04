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
double temp_o, temp_i;
int j;
for (i = 0; i < len; i++) {
    temp_i = ibuf[i];
    temp_o = b0 * temp_i;

    if (i >= 2) {
        temp_o += b1 * ibuf[i-1] + b2 * ibuf[i-2];
        temp_o += a1 * obuf[i-1] + a2 * obuf[i-2];
    } else if (i == 1) {
        temp_o += b1 * i1 + b2 * i2;
        temp_o += a1 * o1 + a2 * o2;
    } else {
        temp_o += b1 * i1 + b2 * i2;
        temp_o += a1 * o1 + a2 * o2;
    }

    out = temp_o * wet + temp_i * dry;

    if (disabled) {
        obuf[i] = (int32_t)temp_i;
    } else if (out < (-2147483647 - 1)) {
        (*clippings)++;
        obuf[i] = (-2147483647 - 1);
    } else if (out > 2147483647) {
        (*clippings)++;
        obuf[i] = 2147483647;
    } else {
        obuf[i] = (int32_t)out;
    }

    i1 = ibuf[i];
    o1 = temp_o;
    i2 = i1;
    o2 = o1;
}
}
