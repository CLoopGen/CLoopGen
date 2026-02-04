#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_cheb_series_struct {
    double *c;
    size_t order;
    double a;
    double b;
    size_t order_sp;
    double *f;
};


typedef struct gsl_cheb_series_struct gsl_cheb_series;

extern  gsl_cheb_series *cs;
extern size_t i;
extern double d1;
extern double d2;
extern double y2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive (forward) traversal with offset indexing
    // Instead of iterating from order down to 1, traverse forward but use mirrored indices
    // to maintain the same logical access order (order -> 1 becomes 0 -> order-1 with reverse mapping)
    size_t n = cs->order;
    for (i = 0; i < n; i++) {
        size_t rev_index = n - i;  // Map forward index i to descending index: n, n-1, ..., 1
        double temp = d1;
        d1 = y2 * d1 - d2 + cs->c[rev_index];
        d2 = temp;
    }
}
