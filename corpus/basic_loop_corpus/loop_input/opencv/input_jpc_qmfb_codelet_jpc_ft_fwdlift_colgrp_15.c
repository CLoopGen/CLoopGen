#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_storage;
static jpc_fix_t *hptr2_storage;

void init_vars() {
    size_t num_elements = 16;

    lptr2_storage = (jpc_fix_t*)aligned_alloc(32, num_elements * sizeof(jpc_fix_t));
    hptr2_storage = (jpc_fix_t*)aligned_alloc(32, num_elements * sizeof(jpc_fix_t));

    if (!lptr2_storage || !hptr2_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx * 2);
        hptr2_storage[idx] = (jpc_fix_t)(idx * 3 + 1);
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
    i = 0;
}