#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

static float *a_data;
static float *b_data;
static BLASLONG total_iterations = 20000;

void init_vars() {
    lda = 8;
    total_iterations = 20000;

    a_data = (float*)calloc((total_iterations - 1) * lda + 8, sizeof(float));
    b_data = (float*)calloc(total_iterations * 8, sizeof(float));

    if (!a_data || !b_data) {
        if (a_data) free(a_data);
        if (b_data) free(b_data);
        exit(1);
    }

    a01 = a_data;
    b = b_data;
}

void cleanup_vars() {
    free(a_data);
    free(b_data);
}