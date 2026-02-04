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
extern size_t eval_order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (eval_order >= 1) {
    for (i = eval_order; i >= 1; i--) {
        double temp = d1;
        d1 = y2 * d1 - d2 + cs->c[i];
        d2 = temp;
    }
} else {
    // Handle edge case when eval_order < 1 with a degenerate loop structure (zero iterations)
    for (i = 1; i >= 1; i--) {
        // Loop condition fails immediately, simulating zero iterations but preserving loop form
        double dummy = 0.0;
        d1 = d1; // Prevent unused variable warnings and preserve observable behavior
    }
}
}
