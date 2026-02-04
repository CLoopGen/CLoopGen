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
    double t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
    t0 = xdbl[7] - xdbl[0];
    t1 = xdbl[8] - xdbl[1];
    t2 = xdbl[9] - xdbl[2];
    t3 = xdbl[10] - xdbl[3];
    t4 = xdbl[11] - xdbl[4];
    t5 = xdbl[0] - xdbl[5];
    t6 = xdbl[1] - xdbl[6];
    t7 = xdbl[2] - xdbl[7];
    t8 = xdbl[3] - xdbl[8];
    t9 = xdbl[4] - xdbl[9];
    t10 = xdbl[5] - xdbl[10];
    t11 = xdbl[6] - xdbl[11];

    y1 = t0 - carry;
    if (y1 < 0) {
        t1 -= one_bit;
        y1 += 1;
    }
    xdbl[0] = y1;

    y2 = t1;
    if (y2 < 0) {
        t2 -= one_bit;
        y2 += 1;
    }
    xdbl[1] = y2;

    y3 = t2;
    if (y3 < 0) {
        t3 -= one_bit;
        y3 += 1;
    }
    xdbl[2] = y3;

    y1 = t3;
    if (y1 < 0) {
        t4 -= one_bit;
        y1 += 1;
    }
    xdbl[3] = y1;

    y2 = t4;
    if (y2 < 0) {
        t5 -= one_bit;
        y2 += 1;
    }
    xdbl[4] = y2;

    y3 = t5;
    if (y3 < 0) {
        t6 -= one_bit;
        y3 += 1;
    }
    xdbl[5] = y3;

    y1 = t6;
    if (y1 < 0) {
        t7 -= one_bit;
        y1 += 1;
    }
    xdbl[6] = y1;

    y2 = t7;
    if (y2 < 0) {
        t8 -= one_bit;
        y2 += 1;
    }
    xdbl[7] = y2;

    y3 = t8;
    if (y3 < 0) {
        t9 -= one_bit;
        y3 += 1;
    }
    xdbl[8] = y3;

    y1 = t9;
    if (y1 < 0) {
        t10 -= one_bit;
        y1 += 1;
    }
    xdbl[9] = y1;

    y2 = t10;
    if (y2 < 0) {
        t11 -= one_bit;
        y2 += 1;
    }
    xdbl[10] = y2;

    y3 = t11;
    if (y3 < 0) {
        carry = one_bit;
        y3 += 1;
    } else {
        carry = 0;
    }
    xdbl[11] = y3;
}
}
