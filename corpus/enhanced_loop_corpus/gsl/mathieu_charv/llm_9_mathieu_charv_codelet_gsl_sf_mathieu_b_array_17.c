#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern unsigned int odd_order;
extern unsigned int ii;
extern unsigned int jj;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int step = 2;
    for (ii = 0; ii < odd_order; ii += step) {
        for (jj = 0; jj < odd_order; jj++) {
            size_t idx = ii * odd_order + jj;
            if (ii == jj) {
                double val = (2 * ii + 1);
                zz[idx] = val * val;
                if (ii + 1 < odd_order && jj + 1 < odd_order) {
                    zz[(ii + 1) * odd_order + (jj + 1)] = (2 * (ii + 1) + 1) * (2 * (ii + 1) + 1);
                }
            } else if (ii == jj + 1) {
                zz[idx] = qq;
                if (ii + 1 < odd_order && jj + 1 < odd_order) {
                    zz[(ii + 1) * odd_order + (jj + 2)] = qq;
                }
            } else if (ii + 1 == jj) {
                zz[idx] = qq;
                if (ii + 1 < odd_order && jj + 1 < odd_order) {
                    zz[(ii + 2) * odd_order + (jj + 1)] = qq;
                }
            }
        }
    }
    for (; ii < odd_order; ii++) {
        for (jj = 0; jj < odd_order; jj++) {
            if (ii == jj)
                zz[ii * odd_order + jj] = (2 * ii + 1) * (2 * ii + 1);
            else if (ii == jj + 1 || ii + 1 == jj)
                zz[ii * odd_order + jj] = qq;
        }
    }
}
