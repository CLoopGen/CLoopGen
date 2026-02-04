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
    double temp_sum = 0.0;
    double temp_fac = fac;
    for (i = 1; i <= n - 2; i++) {
        double temp_val = con * (f->c[i - 1] - f->c[i + 1]) / ((double)i);
        integ->c[i] = temp_val;
        temp_sum += temp_fac * temp_val;
        temp_fac = -temp_fac;
    }
    sum += temp_sum;
}
