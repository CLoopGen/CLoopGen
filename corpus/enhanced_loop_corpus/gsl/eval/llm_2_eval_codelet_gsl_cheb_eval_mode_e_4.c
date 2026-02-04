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



void loop() {
    // Variant 1: Strided memory access with stride of 2 (simulating a non-unit stride pattern)
    // We assume eval_order is even for simplicity, and adjust loop bound accordingly.
    size_t adjusted_order = eval_order - (eval_order % 2); // Make it even
    for (i = adjusted_order; i >= 2; i -= 2) {
        double temp1 = d1;
        d1 = y2 * d1 - d2 + cs->c[i];
        d2 = temp1;

        // Second iteration of the stride: simulate unrolled effect with offset
        double temp2 = d1;
        d1 = y2 * d1 - d2 + cs->c[i-1];
        d2 = temp2;
    }
    // Handle remaining element if needed
    if (eval_order % 2 == 1) {
        double temp = d1;
        d1 = y2 * d1 - d2 + cs->c[1];
        d2 = temp;
    }
}
