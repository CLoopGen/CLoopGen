#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_data;
static jpc_fix_t *hptr2_data;

void init_vars() {
    const size_t total_size = 128 << 20; // ~128 MB of total data
    const size_t element_size = sizeof(jpc_fix_t);
    const size_t num_elements = total_size / (2 * element_size); // Two arrays

    numcols = num_elements;
    stride = 1;

    lptr2_data = aligned_alloc(32, num_elements * element_size);
    hptr2_data = aligned_alloc(32, num_elements * element_size);

    if (!lptr2_data || !hptr2_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_data[idx] = (jpc_fix_t)((idx + 500) % 1000);
    }

    lptr2 = lptr2_data;
    hptr2 = hptr2_data;
}