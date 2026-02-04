#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t K;
size_t i;
size_t j;

static double *data_buf;

void init_vars() {
    const double target_time = 0.01;
    const double cycles_per_iter = 10;
    const double freq_ghz = 3.0;
    const double iter_per_sec = (freq_ghz * 1e9) / cycles_per_iter;
    const double total_iters = target_time * iter_per_sec;

    K = 1;
    while ((K * (K - 1)) / 2 < total_iters && K < (1U << 16)) {
        K++;
    }

    data_buf = aligned_alloc(32, K * sizeof(double));
    if (!data_buf) {
        K = 4096;
    }

    for (size_t idx = 0; idx < K; ++idx) {
        data_buf[idx] = (double)(idx + 1);
    }
}