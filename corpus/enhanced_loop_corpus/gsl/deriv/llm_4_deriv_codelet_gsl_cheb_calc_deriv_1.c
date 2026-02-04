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
extern  size_t n;
extern  double con;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (con == 1.0) {
        return;
    }
    for (i = 0; i < n; i++)
        deriv->c[i] *= con;
}
