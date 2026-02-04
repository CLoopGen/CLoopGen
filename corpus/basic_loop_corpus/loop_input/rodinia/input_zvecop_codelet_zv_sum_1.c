#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int dim;
    u_int max_dim;
    complex *ve;
} ZVEC;

ZVEC *x;
int i;
complex sum;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // ~16M doubles = ~128MB of complex numbers
    const size_t num_elements = data_size / sizeof(complex);

    complex *vec_data = (complex *)calloc(num_elements, sizeof(complex));
    if (!vec_data) exit(1);

    for (size_t idx = 0; idx < num_elements; idx++) {
        vec_data[idx].re = 1.0;
        vec_data[idx].im = 2.0;
    }

    x = (ZVEC *)malloc(sizeof(ZVEC));
    if (!x) exit(1);

    x->dim = num_elements;
    x->max_dim = num_elements;
    x->ve = vec_data;

    i = 0;
    sum.re = 0.0;
    sum.im = 0.0;
}