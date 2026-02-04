#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr_base;
static jpc_fix_t *hptr_base;
static size_t total_elements;

void init_vars() {
    total_elements = (1 << 20); // Approximately 1MB of data for int_fast32_t (each is at least 4 bytes)
    numcols = total_elements / 2; // Ensure sufficient size for the loop
    stride = total_elements / 8;
    
    lptr_base = (jpc_fix_t *)aligned_alloc(64, total_elements * sizeof(jpc_fix_t));
    hptr_base = (jpc_fix_t *)aligned_alloc(64, total_elements * sizeof(jpc_fix_t));

    if (!lptr_base || !hptr_base) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        lptr_base[idx] = (jpc_fix_t)(idx % 1000);
        hptr_base[idx] = (jpc_fix_t)(idx % 500);
    }

    lptr2 = lptr_base;
    hptr2 = hptr_base;
}