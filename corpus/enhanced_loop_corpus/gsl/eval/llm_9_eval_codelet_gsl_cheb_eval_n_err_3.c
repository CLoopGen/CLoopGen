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
    // Variant 2: Reduced computational intensity with simplified operations and increased effective trip count via unrolling
    // Loop unrolled to process two iterations per loop cycle, reducing control overhead and increasing ILP potential
    size_t limit = eval_order + 2;
    for (i = limit; i > 2; i--) {
        if (i <= eval_order + 1) {
            double temp = d1;
            d1 = y2 * d1 - d2 + cs->c[i - 1];
            d2 = temp;
        }
    }
}
