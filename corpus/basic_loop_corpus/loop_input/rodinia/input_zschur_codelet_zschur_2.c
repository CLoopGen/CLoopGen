#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    complex *base;
    complex **me;
} ZMAT;

complex *base_data;
complex **me_data;
ZMAT *A;
int k;
int k_min;
int k_max;

void init_vars() {
    k_min = 0;
    k_max = 5000;  // ensures loop runs about k_max - k_min - 2 iterations

    size_t total_elements = (k_max - k_min + 2) * (k_max - k_min + 2);
    if (total_elements < 1000000) total_elements = 1000000;  // aim for at least ~1MB of data

    base_data = (complex*)calloc(total_elements, sizeof(complex));
    me_data = (complex**)malloc((k_max + 3) * sizeof(complex*));

    for (int i = 0; i <= (int)k_max + 2; i++) {
        me_data[i] = base_data + i * (k_max + 3);
    }

    A = (ZMAT*)malloc(sizeof(ZMAT));
    A->m = k_max + 3;
    A->n = k_max + 3;
    A->max_m = k_max + 3;
    A->max_n = k_max + 3;
    A->max_size = total_elements;
    A->base = base_data;
    A->me = me_data;
}