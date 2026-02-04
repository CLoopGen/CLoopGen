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
    y1 = xdbl[7] - xdbl[0];
    y1 -= carry;
    y2 = xdbl[8] - xdbl[1];
    y3 = xdbl[9] - xdbl[2];
    double t1 = xdbl[10] - xdbl[3];
    double t2 = xdbl[11] - xdbl[4];
    double t3 = xdbl[0] - xdbl[5];
    double t4 = xdbl[1] - xdbl[6];
    double t5 = xdbl[2] - xdbl[7];
    double t6 = xdbl[3] - xdbl[8];
    double t7 = xdbl[4] - xdbl[9];
    double t8 = xdbl[5] - xdbl[10];
    double t9 = xdbl[6] - xdbl[11];

    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    if (y3 < 0) {
        t1 -= one_bit;
        y3 += 1;
    }
    if (t1 < 0) {
        t2 -= one_bit;
        t1 += 1;
    }
    if (t2 < 0) {
        t3 -= one_bit;
        t2 += 1;
    }
    if (t3 < 0) {
        t4 -= one_bit;
        t3 += 1;
    }
    if (t4 < 0) {
        t5 -= one_bit;
        t4 += 1;
    }
    if (t5 < 0) {
        t6 -= one_bit;
        t5 += 1;
    }
    if (t6 < 0) {
        t7 -= one_bit;
        t6 += 1;
    }
    if (t7 < 0) {
        t8 -= one_bit;
        t7 += 1;
    }
    if (t8 < 0) {
        t9 -= one_bit;
        t8 += 1;
    }

    xdbl[0] = y1;
    xdbl[1] = y2;
    xdbl[2] = y3;
    xdbl[3] = t1;
    xdbl[4] = t2;
    xdbl[5] = t3;
    xdbl[6] = t4;
    xdbl[7] = t5;
    xdbl[8] = t6;
    xdbl[9] = t7;
    xdbl[10] = t8;
    if (t9 < 0) {
        carry = one_bit;
        t9 += 1;
    } else {
        carry = 0;
    }
    xdbl[11] = t9;
}
}
