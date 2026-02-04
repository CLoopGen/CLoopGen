#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

extern gsl_histogram2d *h;
extern size_t i;
extern size_t j;
extern size_t i1;
extern size_t i2;
extern size_t i3;
extern size_t i4;
extern size_t _usr_j1;
extern size_t j2;
extern size_t j3;
extern size_t j4;
extern double expected;
extern int status;

// Variable name mappings to avoid conflicts with system symbols
#define j1 _usr_j1



void loop(){
    // Variant 1: Consecutive memory access by flattening the loop into a single loop with sequential traversal
    size_t idx = 0;
    for (idx = 0; idx < 17 * 23; idx++) {
        i = idx / 23;
        j = idx % 23;

        if (i == i1 && j == j1) {
            expected = 1.;
        } else if (i == i2 && j == j2) {
            expected = 2.;
        } else if (i == i3 && j == j3) {
            expected = 3.;
        } else if (i == i4 && j == j4) {
            expected = 4.;
        } else {
            expected = 0.;
        }

        if (h->bin[idx] != expected) {
            status = 1;
        }
    }
}
