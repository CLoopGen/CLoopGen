#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_data;
static jpc_fix_t *hptr2_data;

void init_vars() {
    const int shift = 13;
    const double scale_factor = -1.5861343420599241;
    const int64_t fixed_mult = (int64_t)(scale_factor * (1LL << shift) + (scale_factor >= 0 ? 0.5 : -0.5));

    numcols = 16777216; // ~2^24 elements to ensure ~0.01s runtime
    stride = 1;
    
    lptr2_data = (jpc_fix_t*)aligned_alloc(32, sizeof(jpc_fix_t) * (numcols + stride));
    hptr2_data = (jpc_fix_t*)aligned_alloc(32, sizeof(jpc_fix_t) * numcols);
    
    if (!lptr2_data || !hptr2_data) {
        exit(1);
    }

    for (int idx = 0; idx < numcols + stride; ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx % 65537);
    }
    for (int idx = 0; idx < numcols; ++idx) {
        hptr2_data[idx] = (jpc_fix_t)((idx + 1) % 65537);
    }

    lptr2 = lptr2_data;
    hptr2 = hptr2_data;
}