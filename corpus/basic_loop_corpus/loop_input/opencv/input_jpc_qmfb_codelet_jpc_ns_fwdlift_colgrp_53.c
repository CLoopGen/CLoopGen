#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

jpc_fix_t *hptr2;
int i;

static jpc_fix_t *hptr2_storage;
static size_t total_elements = 16 * 65536; // ~4MB of data to ensure loop runtime

void init_vars() {
    hptr2_storage = (jpc_fix_t*)aligned_alloc(32, total_elements * sizeof(jpc_fix_t));
    if (!hptr2_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        hptr2_storage[idx] = (jpc_fix_t)(idx % 1000);
    }

    hptr2 = hptr2_storage;
}

__attribute__((destructor))
static void cleanup() {
    if (hptr2_storage) {
        free(hptr2_storage);
        hptr2_storage = NULL;
    }
}