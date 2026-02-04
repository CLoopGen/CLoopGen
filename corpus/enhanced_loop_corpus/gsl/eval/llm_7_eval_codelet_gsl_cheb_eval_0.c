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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double d1_prev, d2_prev;
    d1_prev = d1;
    d2_prev = d2;
    for (i = cs->order; i >= 1; i--) {
        double new_d1 = y2 * d1_prev - d2_prev + cs->c[i];
        d2_prev = d1_prev;
        d1_prev = new_d1;
    }
    d1 = d1_prev;
    d2 = d2_prev;
}
