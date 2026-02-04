#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *lut;
int N = 1 << 26; // Approximately 256MB: 2^26 elements * sizeof(float) = 256MB
int n;

void init_vars() {
    lut = (float*)calloc(N, sizeof(float));
    if (!lut) {
        exit(1);
    }
}