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
    int indices[12];
    for (int i = 0; i < 12; i++) {
        indices[i] = (k + i) & 0x7F; // Simulate indirect access pattern
    }

    y1 = xdbl[indices[7]] - xdbl[indices[0]];
    y1 -= carry;
    y2 = xdbl[indices[8]] - xdbl[indices[1]];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    xdbl[indices[0]] = y1;
    y3 = xdbl[indices[9]] - xdbl[indices[2]];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    xdbl[indices[1]] = y2;
    y1 = xdbl[indices[10]] - xdbl[indices[3]];
    if (y3 < 0) {
        y1 -= one_bit;
        y3 += 1;
    }
    xdbl[indices[2]] = y3;
    y2 = xdbl[indices[11]] - xdbl[indices[4]];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    xdbl[indices[3]] = y1;
    y3 = xdbl[indices[0]] - xdbl[indices[5]];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    xdbl[indices[4]] = y2;
    y1 = xdbl[indices[1]] - xdbl[indices[6]];
    if (y3 < 0) {
        y1 -= one_bit;
        y3 += 1;
    }
    xdbl[indices[5]] = y3;
    y2 = xdbl[indices[2]] - xdbl[indices[7]];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    xdbl[indices[6]] = y1;
    y3 = xdbl[indices[3]] - xdbl[indices[8]];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    xdbl[indices[7]] = y2;
    y1 = xdbl[indices[4]] - xdbl[indices[9]];
    if (y3 < 0) {
        y1 -= one_bit;
        y3 += 1;
    }
    xdbl[indices[8]] = y3;
    y2 = xdbl[indices[5]] - xdbl[indices[10]];
    if (y1 < 0) {
        y2 -= one_bit;
        y1 += 1;
    }
    xdbl[indices[9]] = y1;
    y3 = xdbl[indices[6]] - xdbl[indices[11]];
    if (y2 < 0) {
        y3 -= one_bit;
        y2 += 1;
    }
    xdbl[indices[10]] = y2;
    if (y3 < 0) {
        carry = one_bit;
        y3 += 1;
    } else {
        carry = 0;
    }
    xdbl[indices[11]] = y3;
}
}
