#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_buffer;
static jpc_fix_t *hptr2_buffer;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB total data
    const size_t num_elements = data_size / (2 * sizeof(jpc_fix_t)); // Two arrays

    numcols = (int)num_elements;

    lptr2_buffer = aligned_alloc(32, num_elements * sizeof(jpc_fix_t));
    hptr2_buffer = aligned_alloc(32, num_elements * sizeof(jpc_fix_t));

    if (!lptr2_buffer || !hptr2_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_buffer[idx] = (jpc_fix_t)((idx + 500) % 1000);
    }

    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;
}