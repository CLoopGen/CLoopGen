#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

#define DATA_SIZE (64 * 1024 * 1024)
static jpc_fix_t lptr2_data[DATA_SIZE];
static jpc_fix_t hptr2_data[DATA_SIZE];

void init_vars() {
    stride = 1024;
    lptr2 = lptr2_data;
    hptr2 = hptr2_data;

    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        lptr2_data[idx] = (jpc_fix_t)(idx % 100);
        hptr2_data[idx] = (jpc_fix_t)((idx + 50) % 200);
    }
}