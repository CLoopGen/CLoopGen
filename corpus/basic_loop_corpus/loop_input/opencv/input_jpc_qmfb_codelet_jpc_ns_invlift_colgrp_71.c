#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int stride = 16;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data per array

static jpc_fix_t *lptr2_data;
static jpc_fix_t *hptr2_data;

void init_vars() {
    lptr2_data = aligned_alloc(32, DATA_SIZE);
    hptr2_data = aligned_alloc(32, DATA_SIZE);

    if (!lptr2_data || !hptr2_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(jpc_fix_t); ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx % 1000);
        hptr2_data[idx] = (jpc_fix_t)(idx % 1000);
    }

    lptr2 = lptr2_data;
    hptr2 = hptr2_data;
}