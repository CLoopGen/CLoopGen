#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

SwsVector *a;
SwsVector *b;
int i;
int j;
SwsVector *vec;

void init_vars() {
    int a_len = 1000;
    int b_len = 1000;
    int vec_len = a_len + b_len - 1;

    a = (SwsVector *)malloc(sizeof(SwsVector));
    b = (SwsVector *)malloc(sizeof(SwsVector));
    vec = (SwsVector *)malloc(sizeof(SwsVector));

    a->length = a_len;
    b->length = b_len;
    vec->length = vec_len;

    a->coeff = (double *)calloc(a_len, sizeof(double));
    b->coeff = (double *)calloc(b_len, sizeof(double));
    vec->coeff = (double *)calloc(vec_len, sizeof(double));

    for (int idx = 0; idx < a_len; idx++) {
        a->coeff[idx] = (double)(idx % 17) + 1.0;
    }
    for (int idx = 0; idx < b_len; idx++) {
        b->coeff[idx] = (double)(idx % 19) + 1.0;
    }
}