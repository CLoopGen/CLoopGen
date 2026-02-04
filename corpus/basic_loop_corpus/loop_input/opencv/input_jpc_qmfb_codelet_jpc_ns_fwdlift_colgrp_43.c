#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_data;
static jpc_fix_t *hptr2_data;
static size_t data_size;
static size_t num_elements;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB of total data
    num_elements = data_size / (2 * sizeof(jpc_fix_t)); // Two arrays: lptr2 and hptr2

    if (num_elements < 16) {
        num_elements = 16;
    }

    lptr2_data = aligned_alloc(32, num_elements * sizeof(jpc_fix_t));
    hptr2_data = aligned_alloc(32, num_elements * sizeof(jpc_fix_t));

    for (size_t idx = 0; idx < num_elements; ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx & 0x7FFF);
        hptr2_data[idx] = (jpc_fix_t)((idx + 1) & 0x7FFF);
    }

    lptr2 = lptr2_data;
    hptr2 = hptr2_data;
}