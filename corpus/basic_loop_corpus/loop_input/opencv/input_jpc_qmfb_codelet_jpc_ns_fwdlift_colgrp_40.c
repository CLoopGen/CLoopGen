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
static size_t data_size;
static size_t num_elements;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB of data
    num_elements = data_size / sizeof(jpc_fix_t);

    lptr2_storage = (jpc_fix_t*)aligned_alloc(32, data_size);
    hptr2_storage = (jpc_fix_t*)aligned_alloc(32, data_size);

    if (!lptr2_storage || !hptr2_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_storage[idx] = (jpc_fix_t)(idx % 500);
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
}