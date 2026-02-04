#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int stride = 16;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB total data

static jpc_fix_t *lptr2_buffer;
static jpc_fix_t *hptr2_buffer;

void init_vars() {
    lptr2_buffer = (jpc_fix_t*)aligned_alloc(64, DATA_SIZE);
    hptr2_buffer = (jpc_fix_t*)aligned_alloc(64, DATA_SIZE);

    if (!lptr2_buffer || !hptr2_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(jpc_fix_t); ++idx) {
        lptr2_buffer[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_buffer[idx] = (jpc_fix_t)((idx + 500) % 1000);
    }

    lptr2 = lptr2_buffer;
    hptr2 = hptr2_buffer;
}