#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_base;
static jpc_fix_t *hptr2_base;
static size_t data_size;
static size_t num_elements;

void init_vars() {
    data_size = 64 * 1024 * 1024;
    num_elements = data_size / sizeof(jpc_fix_t);
    
    lptr2_base = (jpc_fix_t *)aligned_alloc(32, num_elements * sizeof(jpc_fix_t));
    hptr2_base = (jpc_fix_t *)aligned_alloc(32, num_elements * sizeof(jpc_fix_t));

    if (!lptr2_base || !hptr2_base) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        lptr2_base[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_base[idx] = (jpc_fix_t)((idx + 500) % 1000);
    }

    lptr2 = lptr2_base;
    hptr2 = hptr2_base;
}