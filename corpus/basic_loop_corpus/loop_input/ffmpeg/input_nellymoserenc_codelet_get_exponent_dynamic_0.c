#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int i;
int band = 0;
int best_idx;
float best_val;

float (*opt)[35768];

void init_vars() {
    const int num_bands = 1;
    const int size_per_band = (1 << 15) + 3000; // 32768 + 3000 = 35768

    opt = calloc(num_bands, sizeof(float[35768]));
    if (!opt) {
        exit(EXIT_FAILURE);
    }

    for (int idx = 0; idx < size_per_band; idx++) {
        opt[0][idx] = (float)(rand() % 10000) / 100.0f;
    }

    band = 0;
    best_val = INFINITY;
    best_idx = -1;

    i = 0;
}