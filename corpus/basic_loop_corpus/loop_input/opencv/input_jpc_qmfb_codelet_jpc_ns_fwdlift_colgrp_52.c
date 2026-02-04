#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

jpc_fix_t *lptr2;
int i;

static jpc_fix_t *lptr2_storage;

void init_vars() {
    size_t data_size = 16 * 16 * 1024; // Ensure total size allows at least 16 iterations per loop, scaled to runtime
    lptr2_storage = (jpc_fix_t *)aligned_alloc(64, data_size * sizeof(jpc_fix_t));
    if (!lptr2_storage) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx % 1000);
    }
    lptr2 = lptr2_storage;
}

__attribute__((destructor))
static void cleanup() {
    free(lptr2_storage);
}