#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_buffer;
static jpc_fix_t *hptr2_buffer;

void init_vars() {
    size_t num_elements = 16 + (1 << 20) / sizeof(jpc_fix_t);
    lptr2_buffer = (jpc_fix_t *)calloc(num_elements, sizeof(jpc_fix_t));
    hptr2_buffer = (jpc_fix_t *)calloc(num_elements, sizeof(jpc_fix_t));

    for (size_t idx = 0; idx < num_elements; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx * 4);
        hptr2_buffer[idx] = (jpc_fix_t)(idx * 2 + 1);
    }

    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;
}