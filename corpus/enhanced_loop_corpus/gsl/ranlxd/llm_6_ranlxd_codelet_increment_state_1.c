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
    double temp0 = xdbl[7] - xdbl[0];
    temp0 -= carry;
    double temp1 = xdbl[8] - xdbl[1];
    if (temp0 < 0) {
        temp1 -= one_bit;
        temp0 += 1;
    }
    double temp2 = xdbl[9] - xdbl[2];
    if (temp1 < 0) {
        temp2 -= one_bit;
        temp1 += 1;
    }
    double temp3 = xdbl[10] - xdbl[3];
    if (temp2 < 0) {
        temp3 -= one_bit;
        temp2 += 1;
    }
    double temp4 = xdbl[11] - xdbl[4];
    if (temp3 < 0) {
        temp4 -= one_bit;
        temp3 += 1;
    }
    double temp5 = xdbl[0] - xdbl[5];
    if (temp4 < 0) {
        temp5 -= one_bit;
        temp4 += 1;
    }
    double temp6 = xdbl[1] - xdbl[6];
    if (temp5 < 0) {
        temp6 -= one_bit;
        temp5 += 1;
    }
    double temp7 = xdbl[2] - xdbl[7];
    if (temp6 < 0) {
        temp7 -= one_bit;
        temp6 += 1;
    }
    double temp8 = xdbl[3] - xdbl[8];
    if (temp7 < 0) {
        temp8 -= one_bit;
        temp7 += 1;
    }
    double temp9 = xdbl[4] - xdbl[9];
    if (temp8 < 0) {
        temp9 -= one_bit;
        temp8 += 1;
    }
    double temp10 = xdbl[5] - xdbl[10];
    if (temp9 < 0) {
        temp10 -= one_bit;
        temp9 += 1;
    }
    double temp11 = xdbl[6] - xdbl[11];
    if (temp10 < 0) {
        temp11 -= one_bit;
        temp10 += 1;
    }
    if (temp11 < 0) {
        carry = one_bit;
        temp11 += 1;
    } else {
        carry = 0;
    }
    xdbl[0] = temp0;
    xdbl[1] = temp1;
    xdbl[2] = temp2;
    xdbl[3] = temp3;
    xdbl[4] = temp4;
    xdbl[5] = temp5;
    xdbl[6] = temp6;
    xdbl[7] = temp7;
    xdbl[8] = temp8;
    xdbl[9] = temp9;
    xdbl[10] = temp10;
    xdbl[11] = temp11;
}
}
