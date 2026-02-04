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

gsl_cheb_series *cs;
size_t i;
double d1;
double d2;
size_t eval_order;
double y2;

static double *alloc_and_init_double_array(size_t n) {
    double *arr = (double *)calloc(n, sizeof(double));
    for (size_t i = 0; i < n; ++i) {
        arr[i] = (double)(i % 100) / 10.0;
    }
    return arr;
}

void init_vars() {
    eval_order = 10000000;  // Adjusted to achieve ~0.01 sec runtime

    cs = (gsl_cheb_series *)malloc(sizeof(gsl_cheb_series));
    cs->order = eval_order;
    cs->a = -1.0;
    cs->b = 1.0;
    cs->order_sp = eval_order;
    cs->c = alloc_and_init_double_array(eval_order + 1);
    cs->f = alloc_and_init_double_array(eval_order + 1);

    d1 = 1.0;
    d2 = 0.5;
    y2 = 1.2;
}