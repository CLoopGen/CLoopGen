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

static jpc_fix_t *lptr2_storage;
static jpc_fix_t *hptr2_storage;

void init_vars() {
    const size_t total_data_size = 128 * 1024 * 1024; // 128 MB total data
    const size_t element_size = sizeof(jpc_fix_t);
    const size_t num_elements = total_data_size / (2 * element_size); // Two arrays

    numcols = num_elements;
    stride = 1;
    lptr2_storage = aligned_alloc(64, num_elements * element_size);
    hptr2_storage = aligned_alloc(64, (num_elements + stride) * element_size);

    if (!lptr2_storage || !hptr2_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_storage[idx] = (jpc_fix_t)((idx + 500) % 1000);
    }
    // Initialize extra elements for safe access at hptr2[stride]
    for (int s = 0; s <= stride; ++s) {
        hptr2_storage[num_elements + s] = 0;
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
}

void cleanup_vars() {
    free(lptr2_storage);
    free(hptr2_storage);
}