#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double one_bit;
extern int k;
extern int kmax;
extern double _usr_y1;
extern double y2;
extern double y3;
extern double *xdbl;
extern double carry;

// Variable name mappings to avoid conflicts with system symbols
#define y1 _usr_y1



void loop(){
for (; k <= kmax; k += 12) {
    double temp1, temp2, temp3;
    y1 = xdbl[7] - xdbl[0];
    y1 -= carry;
    y2 = xdbl[8] - xdbl[1];
    y3 = xdbl[9] - xdbl[2];
    temp1 = y1 < 0 ? one_bit : 0;
    temp2 = y2 < 0 ? one_bit : 0;
    temp3 = y3 < 0 ? one_bit : 0;
    if (y1 < 0) y2 -= one_bit;
    if (y2 < 0) y3 -= one_bit;
    if (y3 < 0) y1 -= one_bit;
    y1 += temp1;
    y2 += temp2;
    y3 += temp3;
    xdbl[0] = y1;
    xdbl[1] = y2;
    xdbl[2] = y3;

    y1 = xdbl[10] - xdbl[3];
    y2 = xdbl[11] - xdbl[4];
    y3 = xdbl[0] - xdbl[5];
    temp1 = y1 < 0 ? one_bit : 0;
    temp2 = y2 < 0 ? one_bit : 0;
    temp3 = y3 < 0 ? one_bit : 0;
    if (y1 < 0) y2 -= one_bit;
    if (y2 < 0) y3 -= one_bit;
    if (y3 < 0) y1 -= one_bit;
    y1 += temp1;
    y2 += temp2;
    y3 += temp3;
    xdbl[3] = y1;
    xdbl[4] = y2;
    xdbl[5] = y3;

    y1 = xdbl[1] - xdbl[6];
    y2 = xdbl[2] - xdbl[7];
    y3 = xdbl[3] - xdbl[8];
    temp1 = y1 < 0 ? one_bit : 0;
    temp2 = y2 < 0 ? one_bit : 0;
    temp3 = y3 < 0 ? one_bit : 0;
    if (y1 < 0) y2 -= one_bit;
    if (y2 < 0) y3 -= one_bit;
    if (y3 < 0) y1 -= one_bit;
    y1 += temp1;
    y2 += temp2;
    y3 += temp3;
    xdbl[6] = y1;
    xdbl[7] = y2;
    xdbl[8] = y3;

    y1 = xdbl[4] - xdbl[9];
    y2 = xdbl[5] - xdbl[10];
    y3 = xdbl[6] - xdbl[11];
    temp1 = y1 < 0 ? one_bit : 0;
    temp2 = y2 < 0 ? one_bit : 0;
    temp3 = y3 < 0 ? one_bit : 0;
    if (y1 < 0) y2 -= one_bit;
    if (y2 < 0) y3 -= one_bit;
    if (y3 < 0) y1 -= one_bit;
    y1 += temp1;
    y2 += temp2;
    y3 += temp3;
    xdbl[9] = y1;
    xdbl[10] = y2;

    if (y3 < 0) {
        carry = one_bit;
        y3 += 1;
    } else {
        carry = 0;
    }
    xdbl[11] = y3;
}
}
