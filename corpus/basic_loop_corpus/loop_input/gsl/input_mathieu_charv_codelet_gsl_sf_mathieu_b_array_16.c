#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int odd_order;
unsigned int ii;
double *zz;

void init_vars() {
    odd_order = 4096;  // Ensures odd_order * odd_order * sizeof(double) ≈ 128MB
    zz = (double*)calloc(odd_order * odd_order, sizeof(double));
    if (!zz) {
        exit(1);
    }
}