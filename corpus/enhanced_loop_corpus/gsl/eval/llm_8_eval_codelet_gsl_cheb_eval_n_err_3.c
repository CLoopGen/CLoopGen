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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    // Trip count halved (using step of 2), but each iteration performs more operations including multiplications and additions
    for (i = eval_order; i >= 2; i -= 2) {
        double temp1 = d1;
        double temp2 = d2;
        d1 = y2 * d1 - d2 + cs->c[i] + cs->c[i-1] * 0.5;
        d2 = temp1 * 1.1 - temp2 * 0.9 + cs->c[i] * cs->c[i-1];
    }
    // Handle leftover element if eval_order is odd
    if (eval_order % 2 == 1) {
        double temp = d1;
        d1 = y2 * d1 - d2 + cs->c[1];
        d2 = temp;
    }
}
