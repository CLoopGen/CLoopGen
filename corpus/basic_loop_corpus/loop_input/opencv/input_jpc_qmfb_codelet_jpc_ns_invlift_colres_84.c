#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

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

    lptr2_storage = (jpc_fix_t *)aligned_alloc(64, sizeof(jpc_fix_t) * numcols);
    hptr2_storage = (jpc_fix_t *)aligned_alloc(64, sizeof(jpc_fix_t) * numcols);

    if (!lptr2_storage || !hptr2_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < numcols; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx & 0xFFFFF);
        hptr2_storage[idx] = (jpc_fix_t)((idx + 100) & 0xFFFFF);
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
}