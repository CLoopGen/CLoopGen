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
for (i = 0; i < 17 * 23; i++) {
    size_t idx = i;
    size_t row = idx / 23;
    size_t col = idx % 23;
    double val = 0.0;
    int match = 0;

    if (!match && row == i1 && col == j1) {
        val = 1.0;
        match = 1;
    }
    if (!match && row == i2 && col == j2) {
        val = 2.0;
        match = 1;
    }
    if (!match && row == i3 && col == j3) {
        val = 3.0;
        match = 1;
    }
    if (!match && row == i4 && col == j4) {
        val = 4.0;
        match = 1;
    }

    expected = val;
    if (h->bin[idx] != expected) {
        status = 1;
    }
}
}
