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
    // Variant 2: Reduced computational intensity with expanded trip count via unrolling into simpler operations
    // Loop runs twice as long but each iteration does less; simulates a lower-complexity recurrence
    size_t double_order = eval_order * 2;
    for (i = double_order; i >= 1; i--) {
        if (i % 2 == 1) {
            // Odd step: update d1 using current d1, d2, and coefficient
            d1 = y2 * d1 - d2;
        } else {
            // Even step: add coefficient and shift values (simulate original combined step)
            size_t idx = i / 2;
            double temp = d1;
            d1 = d1 + cs->c[idx];
            d2 = temp;
        }
    }
}
