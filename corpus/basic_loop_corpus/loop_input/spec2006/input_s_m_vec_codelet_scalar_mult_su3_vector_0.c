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

su3_vector *a;
double s;
su3_vector *c;
int i;

void init_vars() {
    const int size = 10000000; // ~192 MB for two arrays of su3_vector
    a = (su3_vector*)aligned_alloc(32, size * sizeof(su3_vector));
    c = (su3_vector*)aligned_alloc(32, size * sizeof(su3_vector));

    if (!a || !c) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < size; idx++) {
        for (int j = 0; j < 3; j++) {
            a[idx].c[j].real = (double)(rand() % 1000) / 10.0;
            a[idx].c[j].imag = (double)(rand() % 1000) / 10.0;
            c[idx].c[j].real = 0.0;
            c[idx].c[j].imag = 0.0;
        }
    }

    s = 1.5;
    i = 0;
}