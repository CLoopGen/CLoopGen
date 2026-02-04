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
    // Variant 1: Strided memory access with reverse traversal using pointer arithmetic
    double *c_ptr = cs->c + eval_order;
    d2 = 0.0; // assumed initialization for consistency
    for (i = eval_order; i >= 1; i--, c_ptr--) {
        double temp = d1;
        d1 = y2 * d1 - d2 + (*c_ptr);
        d2 = temp;
    }
}
