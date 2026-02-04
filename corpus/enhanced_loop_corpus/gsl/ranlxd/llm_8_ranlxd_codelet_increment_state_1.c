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
for (; k <= kmax; k += 6) {
    y1 = xdbl[7] - xdbl[0];
    y1 -= carry;
    y2 = xdbl[8] - xdbl[1];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    xdbl[0] = y1;
    y3 = xdbl[9] - xdbl[2];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    xdbl[1] = y2;
    y1 = xdbl[10] - xdbl[3];
    if (y3 < 0) {
        y1 -= one_bit;
        y3 += 1;
    }
    xdbl[2] = y3;
    y2 = xdbl[11] - xdbl[4];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    xdbl[3] = y1;
    y3 = xdbl[0] - xdbl[5];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    xdbl[4] = y2;
    y1 = xdbl[1] - xdbl[6];
    if (y3 < 0) {
        y1 -= one_bit;
        y3 += 1;
    }
    xdbl[5] = y3;
    carry = (y1 < 0) ? one_bit : 0;
    if (y1 < 0) y1 += 1;
    xdbl[6] = y1;
}
}
