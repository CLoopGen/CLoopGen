#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
jpc_fix_t *lptr2;
int i;

static jpc_fix_t *lptr2_storage = NULL;

void init_vars() {
    const double scale_factor = 1.0 / (1.0 / 1.23017410558578);
    const jpc_fix_t multiplier = (jpc_fix_t)(scale_factor * ((double)(((jpc_fix_t)1) << 13)));

    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * (1UL << 20)) / sizeof(jpc_fix_t);

    lptr2_storage = aligned_alloc(32, total_elements * sizeof(jpc_fix_t));
    if (!lptr2_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx % 2047);
    }

    numcols = (int)(total_elements - 1);
    lptr2 = lptr2_storage;
}