#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
jpc_fix_t *hptr2;
int i;

void init_vars() {
    const double inv_scale = 1.0 / 1.62578613134411;
    const jpc_fix_t factor = (jpc_fix_t)(inv_scale * ((double)(((jpc_fix_t)1) << 13)));

    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data
    const int element_count = data_size / sizeof(jpc_fix_t);

    numcols = element_count - 1; // ensure hptr2[0] access is valid in loop

    jpc_fix_t *data = (jpc_fix_t*)aligned_alloc(32, data_size);
    if (!data) exit(1);

    for (int idx = 0; idx < element_count; ++idx) {
        data[idx] = (jpc_fix_t)(idx % 1000);
    }

    hptr2 = data;

    i = 0;
}