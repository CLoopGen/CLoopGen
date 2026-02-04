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

extern  gsl_cheb_series *cs;
extern size_t i;
extern double d1;
extern double d2;
extern double y2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every second element in reverse, wrapping around using modulo)
    // Here we simulate a strided access pattern on cs->c by stepping with a stride of 2 (in reverse), using modulo to stay in bounds.
    size_t stride = 2;
    size_t n = cs->order;
    for (i = n; i >= 1; i--) {
        size_t idx = (i - 1 + n - ((n - i) * stride) % n) % n + 1; // Reverse strided index
        double temp = d1;
        d1 = y2 * d1 - d2 + cs->c[idx];
        d2 = temp;
    }
}
