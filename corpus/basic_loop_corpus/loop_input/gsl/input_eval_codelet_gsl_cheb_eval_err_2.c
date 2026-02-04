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

static double *c_data = NULL;

void init_vars() {
    cs = (gsl_cheb_series*)malloc(sizeof(gsl_cheb_series));
    if (!cs) exit(1);

    cs->order = 20000000;  // Large enough to run loop ~0.01s on modern CPU

    c_data = (double*)calloc(cs->order + 1, sizeof(double));
    if (!c_data) exit(1);

    for (size_t idx = 0; idx <= cs->order; ++idx) {
        c_data[idx] = (double)(idx % 127 - 63) / 10.0;
    }

    cs->c = c_data;
    cs->a = -1.0;
    cs->b = 1.0;
    cs->order_sp = cs->order;
    cs->f = NULL;

    d1 = 1.0;
    d2 = 0.5;
    y2 = 2.0;
}