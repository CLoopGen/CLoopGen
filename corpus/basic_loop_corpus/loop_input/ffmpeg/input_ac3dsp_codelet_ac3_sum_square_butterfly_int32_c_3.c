#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int64_t sum[4] = {0};

int len;
int i;

int32_t *coef0;
int32_t *coef1;

void init_vars() {
    len = 8000000; // Approximately 32MB of input data (8M * 4 bytes per int32_t * 2 arrays)

    coef0 = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    coef1 = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));

    for (int j = 0; j < len; j++) {
        coef0[j] = (int32_t)(j % 100);
        coef1[j] = (int32_t)((j + 42) % 100);
    }

    sum[0] = 0;
    sum[1] = 0;
    sum[2] = 0;
    sum[3] = 0;
}