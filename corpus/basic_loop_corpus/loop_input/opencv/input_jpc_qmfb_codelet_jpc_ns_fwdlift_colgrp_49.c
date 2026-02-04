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
static size_t num_iterations = 16;

void init_vars() {
    buffer_size = 16; // The loop runs exactly 16 times, so we need at least 16 elements
    lptr2_buffer = (jpc_fix_t*)calloc(buffer_size, sizeof(jpc_fix_t));
    hptr2_buffer = (jpc_fix_t*)calloc(buffer_size, sizeof(jpc_fix_t));

    if (!lptr2_buffer || !hptr2_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < buffer_size; ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx * 10);
        hptr2_buffer[idx] = (jpc_fix_t)(idx * 7 + 3);
    }

    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;
}