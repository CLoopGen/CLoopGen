#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

#define DATA_SIZE (1 << 20)  // ~1MB of data per array

static jpc_fix_t *lptr2_data;
static jpc_fix_t *hptr2_data;

void init_vars() {
    // Initialize stride to a reasonable value to prevent out-of-bounds access
    stride = 64;  // Ensures lptr2[stride] is valid within allocated block

    // Allocate memory blocks for lptr2 and hptr2 with padding for stride access
    lptr2_data = (jpc_fix_t*)aligned_alloc(32, sizeof(jpc_fix_t) * (DATA_SIZE + stride));
    hptr2_data = (jpc_fix_t*)aligned_alloc(32, sizeof(jpc_fix_t) * DATA_SIZE);

    // Initialize arrays to zero (or some deterministic value)
    for (int idx = 0; idx < DATA_SIZE + stride; ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx % 100);
    }
    for (int idx = 0; idx < DATA_SIZE; ++idx) {
        hptr2_data[idx] = (jpc_fix_t)(idx % 50);
    }

    // Set pointers to the beginning of usable regions
    lptr2 = lptr2_data;
    hptr2 = hptr2_data;

    // Initialize loop index
    i = 0;
}