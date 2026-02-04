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
gsl_cheb_series *f;
size_t n;
size_t i;

static double *alloc_and_init_double_array(size_t size) {
    double *arr = (double *)calloc(size, sizeof(double));
    for (size_t idx = 0; idx < size; ++idx) {
        arr[idx] = (double)(idx % 1000) / 10.0;
    }
    return arr;
}

void init_vars() {
    n = 65536 * 4; 

    deriv = (gsl_cheb_series *)malloc(sizeof(gsl_cheb_series));
    f = (gsl_cheb_series *)malloc(sizeof(gsl_cheb_series));

    deriv->order = n;
    deriv->a = -1.0;
    deriv->b = 1.0;
    deriv->order_sp = n;
    deriv->c = alloc_and_init_double_array(n);
    deriv->f = alloc_and_init_double_array(n);

    f->order = n;
    f->a = -1.0;
    f->b = 1.0;
    f->order_sp = n;
    f->c = alloc_and_init_double_array(n);
    f->f = alloc_and_init_double_array(n);

    i = n;
}