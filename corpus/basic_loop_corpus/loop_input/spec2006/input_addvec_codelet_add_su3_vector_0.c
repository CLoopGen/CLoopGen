#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

su3_vector *a = NULL;
su3_vector *b = NULL;
su3_vector *c = NULL;
int i;

void init_vars() {
    const size_t data_size = 1 << 24; // ~16M elements, roughly 192 MB for three arrays
    a = (su3_vector*)calloc(data_size, sizeof(su3_vector));
    b = (su3_vector*)calloc(data_size, sizeof(su3_vector));
    c = (su3_vector*)calloc(data_size, sizeof(su3_vector));

    if (!a || !b || !c) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (size_t j = 0; j < data_size; ++j) {
        for (int k = 0; k < 3; ++k) {
            a[j].c[k].real = (double)rand() / RAND_MAX;
            a[j].c[k].imag = (double)rand() / RAND_MAX;
            b[j].c[k].real = (double)rand() / RAND_MAX;
            b[j].c[k].imag = (double)rand() / RAND_MAX;
        }
    }
}