#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

#define DATA_SIZE (128 << 20)  // ~128 MB of total data

static jpc_fix_t *lptr_base;
static jpc_fix_t *hptr_base;

void init_vars() {
    const size_t element_size = sizeof(jpc_fix_t);
    numcols = (DATA_SIZE / 2) / element_size;  // Use half for each array
    stride = numcols / 4 + 1;  // Ensure stride is within bounds but not too small

    lptr_base = aligned_alloc(32, numcols * element_size);
    hptr_base = aligned_alloc(32, (numcols + stride) * element_size);

    if (!lptr_base || !hptr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < numcols; ++idx) {
        lptr_base[idx] = (jpc_fix_t)(idx & 0xFF);
    }
    for (int idx = 0; idx < numcols + stride; ++idx) {
        hptr_base[idx] = (jpc_fix_t)((idx * 7) & 0xFF);
    }

    lptr2 = lptr_base;
    hptr2 = hptr_base;
    i = 0;
}