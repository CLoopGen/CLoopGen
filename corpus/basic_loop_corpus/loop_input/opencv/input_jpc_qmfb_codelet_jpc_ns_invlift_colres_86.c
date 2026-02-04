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

static jpc_fix_t *lptr2_storage;
static jpc_fix_t *hptr2_storage;

void init_vars() {
    const double target_time = 0.01;
    const double ops_per_sec = 1e9;
    size_t total_ops = (size_t)(target_time * ops_per_sec);
    size_t elements = total_ops > 1000 ? total_ops / 100 : 1000;

    numcols = (int)elements;

    lptr2_storage = aligned_alloc(32, numcols * sizeof(jpc_fix_t));
    hptr2_storage = aligned_alloc(32, numcols * sizeof(jpc_fix_t));

    for (int idx = 0; idx < numcols; ++idx) {
        lptr2_storage[idx] = (jpc_fix_t)(idx & 0x7FFF);
        hptr2_storage[idx] = (jpc_fix_t)((idx + 100) & 0x7FFF);
    }

    lptr2 = lptr2_storage;
    hptr2 = hptr2_storage;
}