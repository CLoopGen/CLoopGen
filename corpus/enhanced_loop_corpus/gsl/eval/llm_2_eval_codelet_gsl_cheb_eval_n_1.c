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
extern size_t eval_order;
extern double y2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping with modulo to stay in bounds)
    // Here we modify the array access pattern to be strided by accessing c[i] with an effective stride
    size_t idx;
    for (i = eval_order; i >= 1; i--) {
        idx = (i * 2) % (eval_order + 1); // Strided and wrapped index to ensure validity
        if (idx == 0) idx = 1; // Ensure index stays at least 1 to match original domain
        double temp = d1;
        d1 = y2 * d1 - d2 + cs->c[idx];
        d2 = temp;
    }
}
