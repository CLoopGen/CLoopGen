#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_storage;
static jpc_fix_t *hptr2_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 262144 elements per array (each element 4 bytes)
    lptr2_storage = (jpc_fix_t*)aligned_alloc(32, data_size * sizeof(jpc_fix_t));
    hptr2_storage = (jpc_fix_t*)aligned_alloc(32, data_size * sizeof(jpc_fix_t));

    for (size_t idx = 0; idx < data_size; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx & 0xFFFF);
        hptr2_storage[idx] = (jpc_fix_t)((idx << 8) & 0xFFFF);
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
}