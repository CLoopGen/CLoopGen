#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
    // Aim for approximately 64MB of data (each array ~32MB)
    // Each element is at least 4 bytes (int_fast32_t), so ~8M elements per array
    total_size = 8000000;
    
    numcols = total_size;
    stride = 1; // Simple case, adjacent rows are one apart

    lptr_base = (jpc_fix_t*)aligned_alloc(32, total_size * sizeof(jpc_fix_t));
    hptr_base = (jpc_fix_t*)aligned_alloc(32, total_size * sizeof(jpc_fix_t));

    if (!lptr_base || !hptr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize arrays with non-zero values for meaningful computation
    for (size_t idx = 0; idx < total_size; ++idx) {
        lptr_base[idx] = (jpc_fix_t)(idx % 1000);
        hptr_base[idx] = (jpc_fix_t)((idx + 10) % 997);
    }

    lptr2 = lptr_base;
    hptr2 = hptr_base;
}