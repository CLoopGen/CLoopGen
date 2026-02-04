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
    double *c = cs->c;
    size_t idx;
    double d1_local = d1;
    double d2_local = d2;
    for (i = eval_order; i >= 1; i--) {
        idx = i;
        double new_d1 = y2 * d1_local - d2_local + c[idx];
        d2_local = d1_local;
        d1_local = new_d1;
    }
    d1 = d1_local;
    d2 = d2_local;
}
