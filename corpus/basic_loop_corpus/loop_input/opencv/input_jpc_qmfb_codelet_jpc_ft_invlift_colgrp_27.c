#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int stride = 64;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB of data

static jpc_fix_t *lptr2_base;
static jpc_fix_t *hptr2_base;

void init_vars() {
    lptr2_base = aligned_alloc(64, DATA_SIZE);
    hptr2_base = aligned_alloc(64, DATA_SIZE);

    if (!lptr2_base || !hptr2_base) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(jpc_fix_t); ++idx) {
        lptr2_base[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_base[idx] = (jpc_fix_t)((idx + 500) % 1000);
    }

    lptr2 = lptr2_base;
    hptr2 = hptr2_base;
}