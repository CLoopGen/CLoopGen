#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_storage;
static jpc_fix_t *hptr2_storage;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB total for both arrays (each ~128 MB)
    const size_t num_elements = data_size / sizeof(jpc_fix_t);

    numcols = (int)num_elements;

    lptr2_storage = aligned_alloc(32, data_size);
    hptr2_storage = aligned_alloc(32, data_size);

    if (!lptr2_storage || !hptr2_storage) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_storage[idx] = (jpc_fix_t)((idx + 500) % 1000);
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
}