#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int *out;
float *in;
float *scaled;
int size;
int is_signed;
int maxval;
float Q34;
float rounding;
int i;

#define DATA_SIZE_MB 64
#define ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(float))

void init_vars() {
    size = ELEMENTS;
    is_signed = 1;
    maxval = 255;
    Q34 = 1.5f;
    rounding = 0.5f;

    in = (float *)aligned_alloc(32, size * sizeof(float));
    scaled = (float *)aligned_alloc(32, size * sizeof(float));
    out = (int *)aligned_alloc(32, size * sizeof(int));

    if (!in || !scaled || !out) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (i = 0; i < size; i++) {
        in[i] = (rand() % 200 - 100) * 0.5f;
        scaled[i] = (rand() % 1000) * 0.01f;
    }
}