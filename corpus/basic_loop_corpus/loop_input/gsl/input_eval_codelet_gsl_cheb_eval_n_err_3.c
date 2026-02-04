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
double y2;
size_t eval_order;

void init_vars() {
    eval_order = 10000000;  // Adjust to target ~0.01 sec runtime

    cs = (gsl_cheb_series*)malloc(sizeof(gsl_cheb_series));
    cs->order = eval_order;
    cs->order_sp = eval_order;
    cs->a = -1.0;
    cs->b = 1.0;
    cs->c = (double*)malloc((eval_order + 1) * sizeof(double));
    cs->f = (double*)malloc((eval_order + 1) * sizeof(double));

    for (size_t j = 0; j <= eval_order; j++) {
        cs->c[j] = (double)(j % 127) / 64.0;
        cs->f[j] = 0.0;
    }

    d1 = 1.0;
    d2 = 0.5;
    y2 = 1.8;
}