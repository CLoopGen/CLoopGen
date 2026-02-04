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
    double temp[12];
    for (int i = 0; i < 12; i++) {
        temp[i] = xdbl[(7 + i) % 12] - xdbl[i % 12];
    }
    y1 = temp[0] - carry;
    if (y1 < 0) {
        y2 = temp[1] - one_bit;
        y1 += 1;
    } else {
        y2 = temp[1];
    }
    xdbl[0] = y1;
    if (y2 < 0) {
        y3 = temp[2] - one_bit;
        y2 += 1;
    } else {
        y3 = temp[2];
    }
    xdbl[1] = y2;
    if (y3 < 0) {
        y1 = temp[3] - one_bit;
        y3 += 1;
    } else {
        y1 = temp[3];
    }
    xdbl[2] = y3;
    if (y1 < 0) {
        y2 = temp[4] - one_bit;
        y1 += 1;
    } else {
        y2 = temp[4];
    }
    xdbl[3] = y1;
    if (y2 < 0) {
        y3 = temp[5] - one_bit;
        y2 += 1;
    } else {
        y3 = temp[5];
    }
    xdbl[4] = y2;
    if (y3 < 0) {
        y1 = temp[6] - one_bit;
        y3 += 1;
    } else {
        y1 = temp[6];
    }
    xdbl[5] = y3;
    if (y1 < 0) {
        y2 = temp[7] - one_bit;
        y1 += 1;
    } else {
        y2 = temp[7];
    }
    xdbl[6] = y1;
    if (y2 < 0) {
        y3 = temp[8] - one_bit;
        y2 += 1;
    } else {
        y3 = temp[8];
    }
    xdbl[7] = y2;
    if (y3 < 0) {
        y1 = temp[9] - one_bit;
        y3 += 1;
    } else {
        y1 = temp[9];
    }
    xdbl[8] = y3;
    if (y1 < 0) {
        y2 = temp[10] - one_bit;
        y1 += 1;
    } else {
        y2 = temp[10];
    }
    xdbl[9] = y1;
    if (y2 < 0) {
        y3 = temp[11] - one_bit;
        y2 += 1;
    } else {
        y3 = temp[11];
    }
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
