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
    double prev_d1, next_d1 = d1, next_d2 = d2;
    for (i = eval_order; i >= 1; i--) {
        prev_d1 = next_d1;
        next_d1 = y2 * next_d1 - next_d2 + cs->c[i];
        next_d2 = prev_d1;
    }
    d1 = next_d1;
    d2 = next_d2;
}
