#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
jpc_fix_t *lptr2;
int i;

static jpc_fix_t *lptr2_buffer = NULL;

void init_vars() {
    const double scale_val = 1.0 / 1.23017410558578;
    const jpc_fix_t multiplier = (jpc_fix_t)(scale_val * ((double)(((jpc_fix_t)1) << 13)));

    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data
    const size_t element_size = sizeof(jpc_fix_t);
    numcols = data_size / element_size;

    lptr2_buffer = (jpc_fix_t*)aligned_alloc(64, data_size);
    if (!lptr2_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int idx = 0; idx < numcols; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx % 1000);
    }

    lptr2 = lptr2_buffer;
}