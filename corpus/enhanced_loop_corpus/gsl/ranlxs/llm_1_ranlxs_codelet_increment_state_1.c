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
for (; k <= kmax; k += 3) {
    for (int step = 0; step < 4; ++step) {
        int offset = step * 3;
        y1 = xdbl[(7 + offset) % 12] - xdbl[(0 + offset) % 12];
        y1 -= (offset == 0) ? carry : 0;
        y2 = xdbl[(8 + offset) % 12] - xdbl[(1 + offset) % 12];
        if (y1 < 0) {
            y2 -= one_bit;
            y1 += 1;
        }
        xdbl[(0 + offset) % 12] = y1;
        y3 = xdbl[(9 + offset) % 12] - xdbl[(2 + offset) % 12];
        if (y2 < 0) {
            y3 -= one_bit;
            y2 += 1;
        }
        xdbl[(1 + offset) % 12] = y2;
        y1 = xdbl[(10 + offset) % 12] - xdbl[(3 + offset) % 12];
        if (y3 < 0) {
            y1 -= one_bit;
            y3 += 1;
        }
        xdbl[(2 + offset) % 12] = y3;
        y2 = xdbl[(11 + offset) % 12] - xdbl[(4 + offset) % 12];
        if (y1 < 0) {
            y2 -= one_bit;
            y1 += 1;
        }
        xdbl[(3 + offset) % 12] = y1;
        y3 = xdbl[(0 + offset) % 12] - xdbl[(5 + offset) % 12];
        if (y2 < 0) {
            y3 -= one_bit;
            y2 += 1;
        }
        xdbl[(4 + offset) % 12] = y2;
        y1 = xdbl[(1 + offset) % 12] - xdbl[(6 + offset) % 12];
        if (y3 < 0) {
            y1 -= one_bit;
            y3 += 1;
        }
        xdbl[(5 + offset) % 12] = y3;

        // Final adjustment only on last unroll step
        if (step == 3) {
            y2 = xdbl[2] - xdbl[7];
            if (y1 < 0) {
                y2 -= one_bit;
                y1 += 1;
            }
            xdbl[6] = y1;
            y3 = xdbl[3] - xdbl[8];
            if (y2 < 0) {
                y3 -= one_bit;
                y2 += 1;
            }
            xdbl[7] = y2;
            y1 = xdbl[4] - xdbl[9];
            if (y3 < 0) {
                y1 -= one_bit;
                y3 += 1;
            }
            xdbl[8] = y3;
            y2 = xdbl[5] - xdbl[10];
            if (y1 < 0) {
                y2 -= one_bit;
                y1 += 1;
            }
            xdbl[9] = y1;
            y3 = xdbl[6] - xdbl[11];
            if (y2 < 0) {
                y3 -= one_bit;
                y2 += 1;
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
}
}
