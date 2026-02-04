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
    for (int unroll_factor = 0; unroll_factor < 2 && k + unroll_factor*6 <= kmax; ++unroll_factor) {
        int offset = unroll_factor * 6;
        y1 = xdbl[7 + offset] - xdbl[0 + offset];
        y1 -= carry;
        y2 = xdbl[8 + offset] - xdbl[1 + offset];
        if (y1 < 0) {
            y2 -= one_bit;
            y1 += 1;
        }
        xdbl[0 + offset] = y1;
        y3 = xdbl[9 + offset] - xdbl[2 + offset];
        if (y2 < 0) {
            y3 -= one_bit;
            y2 += 1;
        }
        xdbl[1 + offset] = y2;
        y1 = xdbl[10 + offset] - xdbl[3 + offset];
        if (y3 < 0) {
            y1 -= one_bit;
            y3 += 1;
        }
        xdbl[2 + offset] = y3;
        y2 = xdbl[11 + offset] - xdbl[4 + offset];
        if (y1 < 0) {
            y2 -= one_bit;
            y1 += 1;
        }
        xdbl[3 + offset] = y1;
        y3 = xdbl[(0 + offset)] - xdbl[5 + offset];
        if (y2 < 0) {
            y3 -= one_bit;
            y2 += 1;
        }
        xdbl[4 + offset] = y2;
        y1 = xdbl[1 + offset] - xdbl[6 + offset];
        if (y3 < 0) {
            y1 -= one_bit;
            y3 += 1;
        }
        xdbl[5 + offset] = y3;

        if (unroll_factor == 0) {
            k += 6;
        }
    }
}
}
