#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *input;
int i;
int16_t *coeff;
int64_t pred;

void init_vars() {
    const int N = 65536; // Size to ensure ~0.01 sec runtime (adjustable)

    input = (int32_t*)aligned_alloc(32, N * sizeof(int32_t));
    coeff = (int16_t*)aligned_alloc(32, 4 * sizeof(int16_t));

    for (int j = 0; j < N; j++) {
        input[j] = (int32_t)(j & 0xFFFF);
    }
    for (int j = 0; j < 4; j++) {
        coeff[j] = (int16_t)(j + 1);
    }

    pred = 0;
    i = 0;
}