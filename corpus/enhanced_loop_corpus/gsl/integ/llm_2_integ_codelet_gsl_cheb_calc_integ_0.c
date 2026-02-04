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



void loop() {
    // Variant 1: Strided memory access (access every second element in reverse order)
    // We simulate a strided and reversed traversal by adjusting the loop index mapping
    size_t step = 2;
    for (i = (n - 2) / step * step; i >= 1; i -= step) {
        if (i > n - 2) continue; // Skip out-of-bound indices due to stride
        integ->c[i] = con * (f->c[i - 1] - f->c[i + 1]) / ((double)i);
        sum += fac * integ->c[i];
        fac = -fac;
    }
}
