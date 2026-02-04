#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_data;
static jpc_fix_t *hptr2_data;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB total for both arrays (each ~4MB), adjust as needed
    numcols = data_size;

    lptr2_data = aligned_alloc(32, data_size * sizeof(jpc_fix_t));
    hptr2_data = aligned_alloc(32, data_size * sizeof(jpc_fix_t));

    if (!lptr2_data || !hptr2_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx & 0x7FFF);
        hptr2_data[idx] = (jpc_fix_t)((idx + 1) & 0x7FFF);
    }

    lptr2 = lptr2_data;
    hptr2 = hptr2_data;
}