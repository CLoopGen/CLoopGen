#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_buffer = NULL;
static jpc_fix_t *hptr2_buffer = NULL;

void init_vars() {
    const size_t total_size = 128 * 1024 * 1024; // 128 MB total for both arrays
    const size_t element_size = sizeof(jpc_fix_t);
    const size_t num_elements = total_size / (2 * element_size); // Split between two arrays

    numcols = (int)num_elements;

    lptr2_buffer = (jpc_fix_t*)aligned_alloc(64, num_elements * element_size);
    hptr2_buffer = (jpc_fix_t*)aligned_alloc(64, num_elements * element_size);

    if (!lptr2_buffer || !hptr2_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_buffer[idx] = (jpc_fix_t)((idx + 100) % 1000);
    }

    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;
}