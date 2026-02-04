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

void init_vars() {
    cs = (gsl_cheb_series*)malloc(sizeof(gsl_cheb_series));
    cs->order = 10000000; // Large enough to run loop ~10M iterations for ~0.01 sec
    cs->a = 1.0;
    cs->b = 2.0;
    cs->order_sp = 0;
    cs->f = NULL;

    cs->c = (double*)malloc((cs->order + 1) * sizeof(double));
    for (size_t j = 0; j <= cs->order; j++) {
        cs->c[j] = (double)(j % 100) / 10.0;
    }

    d1 = 1.5;
    d2 = 0.75;
    y2 = 2.0;
}