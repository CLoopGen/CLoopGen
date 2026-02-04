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



void loop() {
    double *c = deriv->c;
    double con_local = con;
    size_t n_local = n;
    for (i = 0; i < n_local; i++) {
        c[i] = c[i] * con_local;
    }
}
