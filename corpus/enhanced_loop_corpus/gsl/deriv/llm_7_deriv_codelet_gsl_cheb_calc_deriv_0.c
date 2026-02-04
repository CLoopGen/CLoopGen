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
    if (n >= 3) {
        size_t j = n - (n % 2);  // Align to even index for splitting
        for (i = j; i >= 4; i -= 2) {
            deriv->c[i - 3] = deriv->c[i - 1] + 2.0 * (i - 2.0) * f->c[i - 2];
            deriv->c[i - 4] = deriv->c[i - 2] + 2.0 * (i - 3.0) * f->c[i - 3];
        }
        for (; i >= 3; i--) {
            deriv->c[i - 3] = deriv->c[i - 1] + 2.0 * (i - 2.0) * f->c[i - 2];
        }
    }
}
