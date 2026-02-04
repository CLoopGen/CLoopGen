#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *out;
float *in;
float *scaled;
int size;
int is_signed;
int maxval;
float Q34;
float rounding;
int i;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(float);  // ~256MB of float data

    in = (float *)calloc(size, sizeof(float));
    scaled = (float *)calloc(size, sizeof(float));
    out = (int *)malloc(size * sizeof(int));

    if (!in || !scaled || !out) {
        exit(1);
    }

    for (i = 0; i < size; i++) {
        in[i] = (float)(rand() % 1000 - 500);  // Random signed values
        scaled[i] = (float)(rand() % 2000) / 1000.0f;  // Random float between 0 and 2
    }

    is_signed = 1;
    maxval = 255;
    Q34 = 1.5f;
    rounding = 0.5f;
}