#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * (1 << 20)) / sizeof(jpc_fix_t))

static jpc_fix_t *lptr2_storage;
static jpc_fix_t *hptr2_storage;

void init_vars() {
    numcols = TOTAL_ELEMENTS / 2;

    lptr2_storage = (jpc_fix_t *)aligned_alloc(32, numcols * sizeof(jpc_fix_t));
    hptr2_storage = (jpc_fix_t *)aligned_alloc(32, numcols * sizeof(jpc_fix_t));

    if (!lptr2_storage || !hptr2_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < numcols; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_storage[idx] = (jpc_fix_t)((idx + 500) % 1000);
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
}