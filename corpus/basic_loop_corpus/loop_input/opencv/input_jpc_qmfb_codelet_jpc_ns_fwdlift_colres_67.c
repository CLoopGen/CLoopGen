#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
jpc_fix_t *hptr2;
int i;

jpc_fix_t *hptr2_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // ~4MB of data (adjustable for timing)
    hptr2_storage = (jpc_fix_t*)aligned_alloc(64, data_size * sizeof(jpc_fix_t));
    if (!hptr2_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        hptr2_storage[idx] = (jpc_fix_t)(idx % 1000);
    }

    numcols = data_size - 1; // Ensure hptr2[0] access is valid throughout loop
    hptr2 = hptr2_storage;
}