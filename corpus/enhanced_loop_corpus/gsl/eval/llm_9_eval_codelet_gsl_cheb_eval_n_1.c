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
    // Variant 2: Reduced computational load with increased effective trip count via split operations
    for (i = 1; i <= eval_order; i++) {
        // Reverse the iteration direction logically by accessing c from the end
        size_t idx = eval_order - i + 1;
        double temp = d1;
        d1 = y2 * d1;           // First phase: partial computation
        d1 = d1 - d2;            // Second phase: subtract d2
        d1 = d1 + cs->c[idx];    // Final phase: add coefficient
        d2 = temp;
    }
}
