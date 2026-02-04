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
static size_t buffer_size;
static size_t element_count;

void init_vars() {
    element_count = 8 * 1024 * 1024 / sizeof(jpc_fix_t);  // ~8MB total data
    buffer_size = element_count * sizeof(jpc_fix_t);

    lptr2_buffer = (jpc_fix_t *)aligned_alloc(64, buffer_size);
    hptr2_buffer = (jpc_fix_t *)aligned_alloc(64, buffer_size);

    if (!lptr2_buffer || !hptr2_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < element_count; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_buffer[idx] = (jpc_fix_t)(idx % 500);
    }

    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;
}