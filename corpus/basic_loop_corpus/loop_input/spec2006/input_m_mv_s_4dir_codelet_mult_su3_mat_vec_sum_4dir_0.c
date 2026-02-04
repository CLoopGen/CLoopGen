#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex c[3];
} su3_vector;

su3_vector *c;
int i;

void init_vars() {
    c = (su3_vector*)aligned_alloc(32, sizeof(su3_vector));
    if (!c) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (int idx = 0; idx < 3; idx++) {
        c->c[idx].real = 0.0;
        c->c[idx].imag = 0.0;
    }
}