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



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and modified trip count
    size_t limit = (cs->order + 1) / 2;  // Reduce effective trip count by half
    d2 = (cs->order % 2 == 0) ? d2 : -d2; // Adjust initial state based on parity

    for (i = cs->order; i >= 1 && i > cs->order - 2*limit; i -= 2) {
        // Unroll two iterations into one with expanded arithmetic
        double temp1 = d1;
        d1 = y2 * d1 - d2 + cs->c[i];
        d2 = temp1;

        if (i > 1) {
            double temp2 = d1;
            d1 = y2 * d1 - d2 + cs->c[i-1];
            d2 = temp2;
        }
    }

    // Final cleanup if odd number of total iterations
    if (cs->order % 2 == 1 && cs->order >= 1) {
        double temp = d1;
        d1 = y2 * d1 - d2 + cs->c[1];
        d2 = temp;
    }
}
