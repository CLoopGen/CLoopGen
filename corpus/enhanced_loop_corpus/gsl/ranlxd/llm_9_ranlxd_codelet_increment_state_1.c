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
for (; k <= kmax; k += 24) {
    double temp1, temp2, temp3;
    // First half-unroll: indices 7..11 and 0..5 with offset 0
    y1 = xdbl[7] - xdbl[0]; y1 -= carry;
    y2 = xdbl[8] - xdbl[1];
    if (y1 < 0) { y2 -= one_bit; y1 += 1; }
    xdbl[0] = y1;
    y3 = xdbl[9] - xdbl[2];
    if (y2 < 0) { y3 -= one_bit; y2 += 1; }
    xdbl[1] = y2;
    y1 = xdbl[10] - xdbl[3];
    if (y3 < 0) { y1 -= one_bit; y3 += 1; }
    xdbl[2] = y3;
    y2 = xdbl[11] - xdbl[4];
    if (y1 < 0) { y2 -= one_bit; y1 += 1; }
    xdbl[3] = y1;

    // Second segment
    y3 = xdbl[0] - xdbl[5];
    if (y2 < 0) { y3 -= one_bit; y2 += 1; }
    xdbl[4] = y2;
    y1 = xdbl[1] - xdbl[6];
    if (y3 < 0) { y1 -= one_bit; y3 += 1; }
    xdbl[5] = y3;
    y2 = xdbl[2] - xdbl[7];
    if (y1 < 0) { y2 -= one_bit; y1 += 1; }
    xdbl[6] = y1;
    y3 = xdbl[3] - xdbl[8];
    if (y2 < 0) { y3 -= one_bit; y2 += 1; }
    xdbl[7] = y2;

    // Third segment
    y1 = xdbl[4] - xdbl[9];
    if (y3 < 0) { y1 -= one_bit; y3 += 1; }
    xdbl[8] = y3;
    y2 = xdbl[5] - xdbl[10];
    if (y1 < 0) { y2 -= one_bit; y1 += 1; }
    xdbl[9] = y1;
    y3 = xdbl[6] - xdbl[11];
    if (y2 < 0) { y3 -= one_bit; y2 += 1; }
    xdbl[10] = y2;

    // Fourth segment (final wrap-around)
    temp1 = xdbl[7] - xdbl[0];
    temp1 -= (y3 < 0) ? one_bit : 0;
    if (temp1 < 0) {
        temp2 = xdbl[8] - xdbl[1] - one_bit;
        temp1 += 1;
    } else {
        temp2 = xdbl[8] - xdbl[1];
    }
    xdbl[0] = temp1;
    if (temp2 < 0) {
        temp3 = xdbl[9] - xdbl[2] - one_bit;
        temp2 += 1;
    } else {
        temp3 = xdbl[9] - xdbl[2];
    }
    xdbl[1] = temp2;
    carry = (temp3 < 0) ? one_bit : 0;
    xdbl[11] = (temp3 < 0) ? temp3 + 1 : temp3;
}
}
