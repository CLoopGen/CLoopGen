#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h;
extern size_t i;
extern size_t i1;
extern size_t i2;
extern size_t i3;
extern size_t i4;
extern double expected;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 4, unrolled to process multiple elements per iteration
    size_t stride = 4;
    size_t limit = (397 + stride - 1) / stride;
    for (i = 0; i < limit; i++) {
        for (size_t s = 0; s < stride; s++) {
            size_t idx = i * stride + s;
            if (idx >= 397) break;

            if (idx == i1) {
                expected = 1.;
            } else if (idx == i2) {
                expected = 2.;
            } else if (idx == i3) {
                expected = 3.;
            } else if (idx == i4) {
                expected = 4.;
            } else {
                expected = 0.;
            }
            if (h->bin[idx] != expected) {
                status = 1;
            }
        }
    }
}
