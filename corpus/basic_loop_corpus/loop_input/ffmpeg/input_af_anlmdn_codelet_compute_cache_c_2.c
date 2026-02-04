#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *cache;
float *f;
ptrdiff_t S;
ptrdiff_t K;
ptrdiff_t i;
ptrdiff_t jj;
int v;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of float data
    const size_t num_floats = data_size / sizeof(float);

    f = (float *)aligned_alloc(32, data_size);
    cache = (float *)aligned_alloc(32, data_size);

    if (!f || !cache) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_floats; idx++) {
        f[idx] = (float)(idx % 1000) / 100.0f;
        cache[idx] = 0.0f;
    }

    K = 8;
    i = 16;
    jj = 16;
    S = 10000;
    v = 0;

    if (i - K - 1 < 0 || i + K >= (ptrdiff_t)num_floats) {
        exit(1);
    }
    if (jj - K - 1 < 0 || jj + S + K >= (ptrdiff_t)num_floats) {
        exit(1);
    }
    if (v + S > (ptrdiff_t)num_floats) {
        exit(1);
    }
}