#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

su3_vector *a;
double s1;
su3_vector *b;
double s2;
su3_vector *c;
int i;

static su3_vector *alloc_initialized_vector(int size) {
    su3_vector *vec = (su3_vector *)calloc(size, sizeof(su3_vector));
    for (int idx = 0; idx < size; idx++) {
        for (int j = 0; j < 3; j++) {
            vec[idx].c[j].real = 1.0 + idx * 0.01;
            vec[idx].c[j].imag = -1.0 - idx * 0.01;
        }
    }
    return vec;
}

void init_vars() {
    const int size = 64 * 1024 * 1024 / sizeof(su3_vector); // ~64MB of data to target ~0.01s runtime

    a = alloc_initialized_vector(size);
    b = alloc_initialized_vector(size);
    c = (su3_vector *)calloc(size, sizeof(su3_vector));

    s1 = 1.5;
    s2 = 2.5;
    i = 0;
}