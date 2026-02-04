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
for (i = 0; i + 1 < len; i++) {
    double temp_o2 = i2 * b2 + i1 * b1 + ibuf[i] * b0 + o2 * a2 + o1 * a1;
    double temp_i2 = ibuf[i];
    double temp_out = temp_o2 * wet + temp_i2 * dry;
    if (disabled) {
        obuf[i] = temp_i2;
    } else if (temp_out < (-2147483647 - 1)) {
        (*clippings)++;
        obuf[i] = (-2147483647 - 1);
    } else if (temp_out > (2147483647)) {
        (*clippings)++;
        obuf[i] = (2147483647);
    } else {
        obuf[i] = temp_out;
    }
    i++;
    double temp_o1 = i1 * b2 + i2 * b1 + ibuf[i] * b0 + o1 * a2 + temp_o2 * a1;
    double temp_i1 = ibuf[i];
    temp_out = temp_o1 * wet + temp_i1 * dry;
    if (disabled) {
        obuf[i] = temp_i1;
    } else if (temp_out < (-2147483647 - 1)) {
        (*clippings)++;
        obuf[i] = (-2147483647 - 1);
    } else if (temp_out > (2147483647)) {
        (*clippings)++;
        obuf[i] = (2147483647);
    } else {
        obuf[i] = temp_out;
    }
    // Update state variables only after both iterations to reduce WAW and WAR hazards
    o2 = temp_o2;
    i2 = temp_i2;
    o1 = temp_o1;
    i1 = temp_i1;
}
}
