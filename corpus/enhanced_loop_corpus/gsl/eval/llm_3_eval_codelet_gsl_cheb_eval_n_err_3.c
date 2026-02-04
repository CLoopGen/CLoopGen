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
    // Variant 2: Consecutive forward traversal with index remapping (eval_order to 1 becomes 0 to eval_order-1)
    d2 = 0.0; // assumed initialization for consistency
    double temp_d1;
    size_t j;
    for (j = 0; j < eval_order; j++) {
        size_t idx = eval_order - j; // map forward index to descending order: eval_order, ..., 1
        temp_d1 = d1;
        d1 = y2 * d1 - d2 + cs->c[idx];
        d2 = temp_d1;
    }
}
