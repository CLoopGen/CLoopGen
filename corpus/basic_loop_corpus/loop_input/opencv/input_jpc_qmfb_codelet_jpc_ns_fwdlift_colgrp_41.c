#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int stride = 16;

jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_data;
static jpc_fix_t *hptr2_data;

void init_vars() {
    const size_t data_size = 1 << 20; // ~4MB total (each array ~2MB), ensures loop runs long enough
    lptr2_data = aligned_alloc(32, data_size * sizeof(jpc_fix_t));
    hptr2_data = aligned_alloc(32, data_size * sizeof(jpc_fix_t));

    for (size_t idx = 0; idx < data_size; ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_data[idx] = (jpc_fix_t)((idx + 500) % 1000);
    }

    lptr2 = lptr2_data;
    hptr2 = hptr2_data;
}