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
    int indices[12] = {7,8,9,10,11,0,1,2,3,4,5,6};
    double diff[12];
    for (int j = 0; j < 12; j++) {
        int src_idx = indices[j];
        int dst_idx = (src_idx + 5) % 12;
        diff[j] = xdbl[src_idx] - xdbl[dst_idx];
    }
    y1 = diff[0] - carry;
    if (y1 < 0) {
        y2 = diff[1] - one_bit;
        y1 += 1;
    } else {
        y2 = diff[1];
    }
    if (y2 < 0) {
        y3 = diff[2] - one_bit;
        y2 += 1;
    } else {
        y3 = diff[2];
    }
    if (y3 < 0) {
        y1 = diff[3] - one_bit;
        y3 += 1;
    } else {
        y1 = diff[3];
    }
    if (y1 < 0) {
        y2 = diff[4] - one_bit;
        y1 += 1;
    } else {
        y2 = diff[4];
    }
    if (y2 < 0) {
        y3 = diff[5] - one_bit;
        y2 += 1;
    } else {
        y3 = diff[5];
    }
    if (y3 < 0) {
        y1 = diff[6] - one_bit;
        y3 += 1;
    } else {
        y1 = diff[6];
    }
    if (y1 < 0) {
        y2 = diff[7] - one_bit;
        y1 += 1;
    } else {
        y2 = diff[7];
    }
    if (y2 < 0) {
        y3 = diff[8] - one_bit;
        y2 += 1;
    } else {
        y3 = diff[8];
    }
    if (y3 < 0) {
        y1 = diff[9] - one_bit;
        y3 += 1;
    } else {
        y1 = diff[9];
    }
    if (y1 < 0) {
        y2 = diff[10] - one_bit;
        y1 += 1;
    } else {
        y2 = diff[10];
    }
    if (y2 < 0) {
        y3 = diff[11] - one_bit;
        y2 += 1;
    } else {
        y3 = diff[11];
    }
    xdbl[0] = y1;
    xdbl[1] = y2;
    xdbl[2] = y3;
    xdbl[3] = y1;
    xdbl[4] = y2;
    xdbl[5] = y3;
    xdbl[6] = y1;
    xdbl[7] = y2;
    xdbl[8] = y3;
    xdbl[9] = y1;
    xdbl[10] = y2;
    carry = (y3 < 0) ? one_bit : 0;
    xdbl[11] = (y3 < 0) ? y3 + 1 : y3;
}
}
