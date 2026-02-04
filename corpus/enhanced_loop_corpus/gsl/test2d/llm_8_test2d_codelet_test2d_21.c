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
for (i = 0; i < 34; i += 2) {
    for (j = 0; j < 46; j += 2) {
        size_t mapped_i = i / 2;
        size_t mapped_j = j / 2;
        if (mapped_i == i1 && mapped_j == j1) {
            expected = 1.;
        } else if (mapped_i == i2 && mapped_j == j2) {
            expected = 2.;
        } else if (mapped_i == i3 && mapped_j == j3) {
            expected = 3.;
        } else if (mapped_i == i4 && mapped_j == j4) {
            expected = 4.;
        } else {
            expected = 0.;
        }
        if (mapped_i < 17 && mapped_j < 23 && h->bin[mapped_i * 23 + mapped_j] != expected) {
            status = 1;
        }
    }
}
}
