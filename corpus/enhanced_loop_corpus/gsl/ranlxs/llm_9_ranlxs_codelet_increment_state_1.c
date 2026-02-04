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
    // Unroll the original loop body twice and fuse operations
    double temp_y1, temp_y2, temp_y3;

    // First iteration (original k)
    y1 = xdbl[7] - xdbl[0];
    y1 -= carry;
    y2 = xdbl[8] - xdbl[1];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    temp_y1 = y1;
    y3 = xdbl[9] - xdbl[2];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    temp_y2 = y2;
    y1 = xdbl[10] - xdbl[3];
    if (y3 < 0) {
        y1 -= one_bit;
        y3 += 1;
    }
    temp_y3 = y3;
    xdbl[0] = temp_y1; xdbl[1] = temp_y2; xdbl[2] = temp_y3;

    y2 = xdbl[11] - xdbl[4];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    temp_y1 = y1;
    y3 = xdbl[0] - xdbl[5];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    temp_y2 = y2;
    y1 = xdbl[1] - xdbl[6];
    if (y3 < 0) {
        y1 -= one_bit;
        y3 += 1;
    }
    temp_y3 = y3;
    xdbl[3] = temp_y1; xdbl[4] = temp_y2; xdbl[5] = temp_y3;

    y2 = xdbl[2] - xdbl[7];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    temp_y1 = y1;
    y3 = xdbl[3] - xdbl[8];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    temp_y2 = y2;
    y1 = xdbl[4] - xdbl[9];
    if (y3 < 0) {
        y1 -= one_bit;
        y3 += 1;
    }
    temp_y3 = y3;
    xdbl[6] = temp_y1; xdbl[7] = temp_y2; xdbl[8] = temp_y3;

    y2 = xdbl[5] - xdbl[10];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    temp_y1 = y1;
    y3 = xdbl[6] - xdbl[11];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    temp_y2 = y2;
    if (y3 < 0) {
        carry = one_bit;
        y3 += 1;
    } else {
        carry = 0;
    }
    temp_y3 = y3;
    xdbl[9] = temp_y1; xdbl[10] = temp_y2; xdbl[11] = temp_y3;

    // Second iteration (k + 12), simulate next step with updated indices and carry
    y1 = xdbl[7] - xdbl[0];
    y1 -= carry;
    y2 = xdbl[8] - xdbl[1];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    temp_y1 = y1;
    y3 = xdbl[9] - xdbl[2];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    temp_y2 = y2;
    y1 = xdbl[10] - xdbl[3];
    if (y3 < 0) {
        y1 -= one_bit;
        y3 += 1;
    }
    temp_y3 = y3;
    xdbl[0] = temp_y1; xdbl[1] = temp_y2; xdbl[2] = temp_y3;

    y2 = xdbl[11] - xdbl[4];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    temp_y1 = y1;
    y3 = xdbl[0] - xdbl[5];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    temp_y2 = y2;
    y1 = xdbl[1] - xdbl[6];
    if (y3 < 0) {
        y1 -= one_bit;
        y3 += 1;
    }
    temp_y3 = y3;
    xdbl[3] = temp_y1; xdbl[4] = temp_y2; xdbl[5] = temp_y3;

    y2 = xdbl[2] - xdbl[7];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    temp_y1 = y1;
    y3 = xdbl[3] - xdbl[8];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    temp_y2 = y2;
    y1 = xdbl[4] - xdbl[9];
    if (y3 < 0) {
        y1 -= one_bit;
        y3 += 1;
    }
    temp_y3 = y3;
    xdbl[6] = temp_y1; xdbl[7] = temp_y2; xdbl[8] = temp_y3;

    y2 = xdbl[5] - xdbl[10];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    temp_y1 = y1;
    y3 = xdbl[6] - xdbl[11];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    temp_y2 = y2;
    if (y3 < 0) {
        carry = one_bit;
        y3 += 1;
    } else {
        carry = 0;
    }
    temp_y3 = y3;
    xdbl[9] = temp_y1; xdbl[10] = temp_y2; xdbl[11] = temp_y3;
}
}
