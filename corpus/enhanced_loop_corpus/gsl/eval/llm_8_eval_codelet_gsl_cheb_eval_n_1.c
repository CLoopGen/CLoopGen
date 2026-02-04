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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    size_t step = 2;
    for (i = eval_order; i >= 1; i -= step) {
        double temp1 = d1;
        d1 = y2 * d1 - d2 + cs->c[i];
        d2 = temp1;

        if (i > 1) {
            double temp2 = d1;
            d1 = y2 * d1 - d2 + cs->c[i-1];
            d2 = temp2;
        }
    }
}
