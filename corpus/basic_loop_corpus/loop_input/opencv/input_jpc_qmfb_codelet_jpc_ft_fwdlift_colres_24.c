#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_storage;
static jpc_fix_t *hptr2_storage;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data to target ~0.01 sec runtime
    const size_t num_elements = data_size / sizeof(jpc_fix_t);

    numcols = (int)num_elements;

    lptr2_storage = calloc(num_elements, sizeof(jpc_fix_t));
    hptr2_storage = calloc(num_elements, sizeof(jpc_fix_t));

    if (!lptr2_storage || !hptr2_storage) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        hptr2_storage[idx] = (jpc_fix_t)(idx & 0xFF);
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
}