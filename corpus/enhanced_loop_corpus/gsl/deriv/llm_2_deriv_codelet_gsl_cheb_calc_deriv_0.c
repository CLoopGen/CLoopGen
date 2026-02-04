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

extern gsl_cheb_series *deriv;
extern  gsl_cheb_series *f;
extern  size_t n;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of accessing deriv->c[i-3] and f->c[i-2] in reverse order,
    // rewrite loop to traverse forward with adjusted indexing for spatial locality.
    size_t start = 3;
    size_t end = n;
    if (end < start) return;
    
    double *deriv_c = deriv->c;
    double *f_c = f->c;
    
    for (i = start; i <= end; i++) {
        size_t idx_deriv_write = i - 3;
        size_t idx_deriv_read = i - 1;
        size_t idx_f_read = i - 2;
        deriv_c[idx_deriv_write] = deriv_c[idx_deriv_read] + 2. * (i - 2.) * f_c[idx_f_read];
    }
}
