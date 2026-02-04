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
static size_t buffer_size = 16777216; // ~64 MB of data (each array 32MB), ensures loop runs long enough

void init_vars() {
    lptr2_buffer = (jpc_fix_t*)aligned_alloc(32, buffer_size * sizeof(jpc_fix_t));
    hptr2_buffer = (jpc_fix_t*)aligned_alloc(32, buffer_size * sizeof(jpc_fix_t));

    if (!lptr2_buffer || !hptr2_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < buffer_size; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx & 0xFFFFF);
        hptr2_buffer[idx] = (jpc_fix_t)((idx << 5) & 0xFFFFF);
    }

    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;
}