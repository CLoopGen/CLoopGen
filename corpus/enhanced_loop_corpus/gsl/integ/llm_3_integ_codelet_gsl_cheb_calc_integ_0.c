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
    // Variant 2: Consecutive forward access with temporary array-like accumulation
    // Introduce a temporary pointer to enable consecutive, cache-friendly writes via offset
    double *temp_c = integ->c + 1;  // Base pointer starting at c[1]
    const double *f_c = f->c;
    double temp_sum = sum;
    double temp_fac = fac;

    for (i = 0; i <= n - 3; i++) {  // Reindex loop from 0 to (n-3)
        temp_c[i] = con * (f_c[i] - f_c[i + 2]) / (double)(i + 1);
        temp_sum += temp_fac * temp_c[i];
        temp_fac = -temp_fac;
    }

    // Update shared variables
    sum = temp_sum;
    fac = temp_fac;
}
