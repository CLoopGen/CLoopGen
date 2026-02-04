#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_base;
static jpc_fix_t *hptr2_base;
static size_t total_elements = 1 << 20; // ~1M elements for sufficient workload

void init_vars() {
    stride = 16; // chosen to avoid overlap and keep access valid
    size_t data_size = total_elements * sizeof(jpc_fix_t);

    lptr2_base = aligned_alloc(32, data_size);
    hptr2_base = aligned_alloc(32, data_size);

    if (!lptr2_base || !hptr2_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        lptr2_base[idx] = (jpc_fix_t)(idx & 0xFFFF);
        hptr2_base[idx] = (jpc_fix_t)((idx + 1) & 0xFFFF);
    }

    lptr2 = lptr2_base;
    hptr2 = hptr2_base;
}