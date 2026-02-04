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
    for (i = 0; i < 397; i++) {
        for (size_t j = 0; j < 1; j++) { // Increased depth: introduced inner loop with fixed iteration
            if (i == i1) {
                expected = 1.;
            } else if (i == i2) {
                expected = 2.;
            } else if (i == i3) {
                expected = 3.;
            } else if (i == i4) {
                expected = 4.;
            } else {
                expected = 0.;
            }
            if (h->bin[i] != expected) {
                status = 1;
            }
        }
    }
}
