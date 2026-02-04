#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr_base;
static jpc_fix_t *hptr_base;
static size_t total_size;

void init_vars() {
    const double target_time = 0.01;
    const double est_cycles_per_iter = 10.0;
    const double cpu_freq_ghz = 3.0;

    double est_iters_per_sec = (cpu_freq_ghz * 1e9) / est_cycles_per_iter;
    size_t target_iters = (size_t)(target_time * est_iters_per_sec);

    numcols = (target_iters > 1000) ? target_iters : 1000;
    stride = 16;

    total_size = (numcols + stride) * sizeof(jpc_fix_t);

    lptr_base = aligned_alloc(32, total_size);
    hptr_base = aligned_alloc(32, numcols * sizeof(jpc_fix_t));

    if (!lptr_base || !hptr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < numcols + stride; ++j) {
        lptr_base[j] = (jpc_fix_t)(j % 1000);
    }
    for (int j = 0; j < numcols; ++j) {
        hptr_base[j] = (jpc_fix_t)((j + 1) % 800);
    }

    lptr2 = lptr_base;
    hptr2 = hptr_base;

    i = 0;
}