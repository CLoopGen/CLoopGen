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
    // Variant 2: Indirect memory access using an index map to simulate non-sequential traversal
    size_t indices[397];
    for (i = 0; i < 397; i++) {
        indices[i] = i; // Identity mapping, but structure allows arbitrary reordering
    }
    // Simulate shuffled access pattern (e.g., reverse order)
    for (i = 0; i < 397; i++) {
        size_t idx = indices[396 - i]; // Reverse access

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
