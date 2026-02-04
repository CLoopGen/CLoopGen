#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

su3_vector *a;
su3_vector *b;
su3_vector *c;
int i;

void init_vars() {
    const int size = 1 << 20;  // Approximately 1 million elements for ~0.01 sec runtime
    a = (su3_vector*)calloc(size, sizeof(su3_vector));
    b = (su3_vector*)calloc(size, sizeof(su3_vector));
    c = (su3_vector*)calloc(size, sizeof(su3_vector));

    for (int idx = 0; idx < size; idx++) {
        for (int j = 0; j < 3; j++) {
            a[idx].c[j].real = (double)(idx + j);
            a[idx].c[j].imag = (double)(idx - j);
            b[idx].c[j].real = (double)(idx * 0.5);
            b[idx].c[j].imag = (double)(j * 0.5);
        }
    }
}