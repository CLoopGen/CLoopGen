#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_buffer;
static jpc_fix_t *hptr2_buffer;
static size_t data_size = 1 << 20; // ~8MB total data (each array ~4MB)

void init_vars() {
    if (lptr2_buffer == NULL) {
        lptr2_buffer = aligned_alloc(64, data_size * sizeof(jpc_fix_t));
        hptr2_buffer = aligned_alloc(64, data_size * sizeof(jpc_fix_t));
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx & 0xFFFF);
        hptr2_buffer[idx] = (jpc_fix_t)((idx << 8) & 0xFFFFFF);
    }

    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;
}