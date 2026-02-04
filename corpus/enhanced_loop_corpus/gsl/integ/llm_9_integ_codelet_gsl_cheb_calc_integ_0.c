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

extern gsl_cheb_series *integ;
extern  gsl_cheb_series *f;
extern  size_t n;
extern  double con;
extern double sum;
extern double fac;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t unroll_factor = 3;
    size_t limit = (n - 2) / unroll_factor * unroll_factor;
    sum = 0.0; // Reset sum for consistent computational effect
    fac = 1.0; // Reset fac to ensure deterministic behavior

    for (i = 1; i <= limit; i += unroll_factor) {
        for (size_t j = 0; j < unroll_factor && (i + j) <= n - 2; j++) {
            size_t idx = i + j;
            integ->c[idx] = con * (f->c[idx - 1] - f->c[idx + 1]) / ((double)idx);
            sum += fac * integ->c[idx];
            fac = -fac;
        }
    }

    // Handle remaining iterations
    for (; i <= n - 2; i++) {
        integ->c[i] = con * (f->c[i - 1] - f->c[i + 1]) / ((double)i);
        sum += fac * integ->c[i];
        fac = -fac;
    }
}
