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

gsl_cheb_series *integ;
gsl_cheb_series *f;
size_t n;
double con;
double sum;
double fac;
size_t i;

static double *alloc_aligned_double_array(size_t count) {
    void *ptr;
    if (posix_memalign(&ptr, 32, count * sizeof(double)) != 0) {
        exit(1);
    }
    return (double *)ptr;
}

void init_vars() {
    n = 16777216;  // ~128 MB of data (each array ~134 MB), adjust for ~0.01s runtime

    con = 1.5;
    sum = 0.0;
    fac = 1.0;

    // Allocate arrays with extra padding to prevent out-of-bounds access
    double *c_f = alloc_aligned_double_array(n + 4);  // f->c: indices up to n-2+1 = n-1 -> need n+1, add padding
    double *c_integ = alloc_aligned_double_array(n + 4); // integ->c: indices 1 to n-2

    // Initialize f->c with dummy values
    for (size_t j = 0; j < n + 4; j++) {
        c_f[j] = (double)(j % 100) / 100.0;
    }

    // Allocate and initialize f and integ structures
    f = (gsl_cheb_series*)calloc(1, sizeof(gsl_cheb_series));
    integ = (gsl_cheb_series*)calloc(1, sizeof(gsl_cheb_series));

    if (!f || !integ || !c_f || !c_integ) {
        exit(1);
    }

    f->c = c_f;
    f->order = n;
    f->a = -1.0;
    f->b = 1.0;
    f->order_sp = n;
    f->f = NULL;

    integ->c = c_integ;
    integ->order = n;
    integ->a = -1.0;
    integ->b = 1.0;
    integ->order_sp = n;
    integ->f = NULL;

    // Ensure loop bounds are safe: i from 1 to n-2 inclusive
    // f->c[i-1], f->c[i+1] must be valid -> i+1 <= n+1 at max, so we need f->c up to index n-1
    // Our allocation of n+4 elements ensures this is safe for n up to 16M
}