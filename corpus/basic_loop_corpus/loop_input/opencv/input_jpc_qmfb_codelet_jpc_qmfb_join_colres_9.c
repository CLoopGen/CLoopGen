#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *srcptr2;
jpc_fix_t *dstptr2;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data to target ~0.01s runtime

static jpc_fix_t src_data[DATA_SIZE / sizeof(jpc_fix_t)];
static jpc_fix_t dst_data[DATA_SIZE / sizeof(jpc_fix_t)];

void init_vars() {
    numcols = DATA_SIZE / sizeof(jpc_fix_t);

    for (int idx = 0; idx < numcols; ++idx) {
        src_data[idx] = (jpc_fix_t)(idx & 0x7FFF);
    }

    srcptr2 = src_data;
    dstptr2 = dst_data;
}