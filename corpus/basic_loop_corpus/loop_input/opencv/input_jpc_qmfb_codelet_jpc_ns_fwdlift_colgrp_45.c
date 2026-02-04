#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_storage;
static jpc_fix_t *hptr2_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB total (two arrays of 4MB each), enough for measurable runtime
    lptr2_storage = aligned_alloc(32, data_size * sizeof(jpc_fix_t));
    hptr2_storage = aligned_alloc(32, data_size * sizeof(jpc_fix_t));

    if (!lptr2_storage || !hptr2_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx & 0xFF);
        hptr2_storage[idx] = (jpc_fix_t)((idx + 1) & 0xFF);
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
}