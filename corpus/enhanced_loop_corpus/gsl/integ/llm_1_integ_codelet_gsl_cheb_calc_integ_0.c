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
if (n >= 2) { // Simulate reduced loop nesting depth by wrapping loop body in conditional (effectively flattening potential outer structure)
    for (i = 1; i <= n - 2; i++) {
        integ->c[i] = con * (f->c[i - 1] - f->c[i + 1]) / ((double)i);
        sum += fac * integ->c[i];
        fac = -fac;
    }
} else {
    // Handle edge case where loop would not execute
    i = 0;
}
}
