#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct cheb_series_struct {
    double *c;
    int order;
    double a;
    double b;
    int order_sp;
};

typedef struct cheb_series_struct cheb_series;

int j;
double d;
double dd;
double y2;
int eval_order;
cheb_series *cs;

static double *c_data;
static cheb_series cs_storage;

void init_vars() {
    eval_order = 1000000;  // Large enough to take ~0.01s
    d = 1.0;
    dd = 0.5;
    y2 = 1.2;

    // Allocate coefficient array with size eval_order + 1 to avoid out-of-bounds access
    c_data = (double*)malloc((eval_order + 1) * sizeof(double));
    if (!c_data) {
        exit(1);
    }

    // Initialize coefficients with dummy data
    for (int i = 0; i <= eval_order; i++) {
        c_data[i] = (double)(i + 1) * 0.001;
    }

    // Initialize cheb_series structure
    cs_storage.c = c_data;
    cs_storage.order = eval_order;
    cs_storage.a = -1.0;
    cs_storage.b = 1.0;
    cs_storage.order_sp = eval_order;

    cs = &cs_storage;
}