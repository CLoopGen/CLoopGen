#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

size_t N;
double *alpha;
double *c;
double *z;
size_t i;

void init_vars() {
    const double min_size_mb = 1.0;
    const double max_size_mb = 256.0;
    double target_time_seconds = 0.01;
    double avg_ops_per_cycle = 2.0;
    uint64_t cycles_per_second = 3000000000ULL;
    uint64_t estimated_ops = (uint64_t)(target_time_seconds * cycles_per_second / avg_ops_per_cycle);

    N = estimated_ops;
    size_t bytes = N * sizeof(double);
    double size_mb = bytes / (1024.0 * 1024.0);

    if (size_mb < min_size_mb) {
        N = (size_t)((min_size_mb * 1024.0 * 1024.0) / sizeof(double));
    } else if (size_mb > max_size_mb) {
        N = (size_t)((max_size_mb * 1024.0 * 1024.0) / sizeof(double));
    }

    alpha = (double*)aligned_alloc(32, N * sizeof(double));
    c = (double*)aligned_alloc(32, N * sizeof(double));
    z = (double*)aligned_alloc(32, N * sizeof(double));

    for (size_t idx = 0; idx < N; idx++) {
        alpha[idx] = 1.0 + (double)(rand() % 1000) / 1000.0;
        z[idx] = (double)(rand() % 10000) / 1000.0;
        c[idx] = 0.0;
    }
}