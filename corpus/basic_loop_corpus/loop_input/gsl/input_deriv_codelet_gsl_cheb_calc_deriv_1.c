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

gsl_cheb_series *deriv;
size_t n;
double con;
size_t i;

void init_vars() {
    n = 16777216; // ~128 MB of data (16M * sizeof(double) = ~128MB), adjust for ~0.01s runtime
    con = 1.5;

    deriv = (gsl_cheb_series *)malloc(sizeof(gsl_cheb_series));
    if (!deriv) exit(1);

    deriv->c = (double *)aligned_alloc(32, n * sizeof(double));
    if (!deriv->c) exit(1);

    deriv->order = n;
    deriv->a = 0.0;
    deriv->b = 1.0;
    deriv->order_sp = 0;
    deriv->f = NULL;

    for (size_t idx = 0; idx < n; idx++) {
        deriv->c[idx] = 1.0 + (idx * 0.001);
    }
}