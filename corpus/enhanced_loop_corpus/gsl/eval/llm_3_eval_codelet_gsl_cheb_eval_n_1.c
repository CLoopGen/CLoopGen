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
    // Variant 2: Consecutive forward traversal with index reversal
    // Instead of iterating from high to low, reverse the loop order and adjust indexing accordingly
    // Map i from increasing loop counter to decreasing original index
    size_t rev_i;
    for (i = 1; i <= eval_order; i++) {
        rev_i = eval_order - i + 1; // Reverse index: eval_order, eval_order-1, ..., 1
        double temp = d1;
        d1 = y2 * d1 - d2 + cs->c[rev_i];
        d2 = temp;
    }
}
