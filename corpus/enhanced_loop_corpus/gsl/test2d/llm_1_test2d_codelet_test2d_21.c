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
for (i = 0; i < 391; i++) { // Flattened 17x23 loop into a single loop
    size_t idx_i = i / 23;
    size_t idx_j = i % 23;
    expected = 0.;
    if (idx_i == i1 && idx_j == j1) {
        expected = 1.;
    } else if (idx_i == i2 && idx_j == j2) {
        expected = 2.;
    } else if (idx_i == i3 && idx_j == j3) {
        expected = 3.;
    } else if (idx_i == i4 && idx_j == j4) {
        expected = 4.;
    }
    if (h->bin[i] != expected) {
        status = 1;
    }
}
}
