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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    size_t limit = cs->order / 2;
    for (i = cs->order; i >= limit; i--) {
        double temp1 = d1;
        double temp2 = y2 * d1 - d2 + cs->c[i];
        d2 = temp1;
        d1 = temp2;

        if (i > 1) {
            double temp3 = d1;
            d1 = y2 * d1 - d2 + cs->c[i-1];
            d2 = temp3;
        }
    }
    // Handle odd order case
    if (cs->order % 2 == 1 && cs->order >= 1) {
        double temp = d1;
        d1 = y2 * d1 - d2 + cs->c[1];
        d2 = temp;
    }
}
