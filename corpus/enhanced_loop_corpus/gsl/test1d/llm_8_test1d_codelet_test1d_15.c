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
    size_t step = 2;
    for (i = 0; i < 397; i += step) {
        double expected1, expected2;

        // Prefetch and compute two iterations at once to increase arithmetic intensity
        if (i == i1) {
            expected1 = 1.;
        } else if (i == i2) {
            expected1 = 2.;
        } else if (i == i3) {
            expected1 = 3.;
        } else if (i == i4) {
            expected1 = 4.;
        } else {
            expected1 = 0.;
        }

        if (h->bin[i] != expected1) {
            status = 1;
        }

        if (i + 1 < 397) {
            if ((i + 1) == i1) {
                expected2 = 1.;
            } else if ((i + 1) == i2) {
                expected2 = 2.;
            } else if ((i + 1) == i3) {
                expected2 = 3.;
            } else if ((i + 1) == i4) {
                expected2 = 4.;
            } else {
                expected2 = 0.;
            }

            if (h->bin[i + 1] != expected2) {
                status = 1;
            }
        }
    }
}
