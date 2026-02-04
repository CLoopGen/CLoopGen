#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_data = NULL;
static jpc_fix_t *hptr2_data = NULL;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB total (two arrays)
    const size_t num_elements = data_size / (2 * sizeof(jpc_fix_t));
    
    numcols = (int)num_elements;

    lptr2_data = aligned_alloc(32, num_elements * sizeof(jpc_fix_t));
    hptr2_data = aligned_alloc(32, num_elements * sizeof(jpc_fix_t));

    if (!lptr2_data || !hptr2_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx & 0xFF);
        hptr2_data[idx] = (jpc_fix_t)((idx + 32) & 0xFF);
    }

    lptr2 = lptr2_data;
    hptr2 = hptr2_data;
}