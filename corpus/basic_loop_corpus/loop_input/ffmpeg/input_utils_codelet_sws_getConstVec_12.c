#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

double c = 1.5;
int length;
int i;
SwsVector *vec;

void init_vars() {
    length = 16777216;  // 16M doubles = ~128 MB, target ~0.01 sec on modern CPU
    vec = (SwsVector*)malloc(sizeof(SwsVector));
    vec->coeff = (double*)malloc(length * sizeof(double));
    vec->length = length;
}