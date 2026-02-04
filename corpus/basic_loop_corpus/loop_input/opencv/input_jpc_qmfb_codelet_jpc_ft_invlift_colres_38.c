#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_data;
static jpc_fix_t *hptr2_data;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (adjustable)
    numcols = data_size / sizeof(jpc_fix_t);
    
    lptr2_data = aligned_alloc(64, data_size);
    hptr2_data = aligned_alloc(64, data_size);

    if (!lptr2_data || !hptr2_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < numcols; ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx & 0xFF);
        hptr2_data[idx] = (jpc_fix_t)((idx + 10) & 0xFF);
    }

    lptr2 = lptr2_data;
    hptr2 = hptr2_data;
}