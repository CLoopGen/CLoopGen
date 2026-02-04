#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

jpc_fix_t *lptr2;
int i;

static jpc_fix_t *buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // ~4MB of data (1M elements * 4 bytes)
    buffer = (jpc_fix_t*)aligned_alloc(32, data_size * sizeof(jpc_fix_t));
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        buffer[idx] = (jpc_fix_t)(idx % 1000);
    }

    lptr2 = buffer;
}

__attribute__((destructor))
static void cleanup() {
    if (buffer) {
        free(buffer);
        buffer = NULL;
    }
}