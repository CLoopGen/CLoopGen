#include <inttypes.h>
#include <stdlib.h>

typedef int_fast32_t jpc_fix_t;

jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_buffer;
static jpc_fix_t *hptr2_buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data per buffer
    lptr2_buffer = (jpc_fix_t *)aligned_alloc(64, data_size * sizeof(jpc_fix_t));
    hptr2_buffer = (jpc_fix_t *)aligned_alloc(64, data_size * sizeof(jpc_fix_t));

    if (!lptr2_buffer || !hptr2_buffer) {
        abort();
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx & 0xFF);
        hptr2_buffer[idx] = (jpc_fix_t)((idx + 123) & 0xFF);
    }

    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;
}