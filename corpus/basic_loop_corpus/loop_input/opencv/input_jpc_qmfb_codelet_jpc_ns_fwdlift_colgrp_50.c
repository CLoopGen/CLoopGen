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

static jpc_fix_t lptr2_data[256 * 1024 * 1024 / (2 * sizeof(jpc_fix_t)) + 16];
static jpc_fix_t hptr2_data[256 * 1024 * 1024 / (2 * sizeof(jpc_fix_t)) + 16 + 1024];

void init_vars() {
    lptr2 = lptr2_data;
    hptr2 = hptr2_data;
    for (int idx = 0; idx < 16; ++idx) {
        hptr2[idx] = (jpc_fix_t)(idx + 1);
        hptr2[idx + stride] = (jpc_fix_t)(idx + 17);
        lptr2[idx] = (jpc_fix_t)(idx * 2);
    }
}