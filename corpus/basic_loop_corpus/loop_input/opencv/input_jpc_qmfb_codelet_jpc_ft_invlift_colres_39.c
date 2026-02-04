#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
jpc_fix_t *lptr2;
int i;

void init_vars() {
    numcols = 67108864;  // 64M elements, each jpc_fix_t is at least 4 bytes -> ~256MB
    jpc_fix_t *data = (jpc_fix_t *)aligned_alloc(32, numcols * sizeof(jpc_fix_t));
    if (!data) {
        exit(1);
    }
    for (int idx = 0; idx < numcols; ++idx) {
        data[idx] = (jpc_fix_t)(idx * 2 + 1);
    }
    lptr2 = data;
}