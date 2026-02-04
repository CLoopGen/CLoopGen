#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB total (two arrays of 4-byte ints)
    numcols = data_size;

    lptr2 = aligned_alloc(32, numcols * sizeof(jpc_fix_t));
    hptr2 = aligned_alloc(32, numcols * sizeof(jpc_fix_t));

    if (!lptr2 || !hptr2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < numcols; ++idx) {
        lptr2[idx] = (jpc_fix_t)(idx & 0x7FFF);
        hptr2[idx] = (jpc_fix_t)((idx + 12345) & 0x7FFF);
    }

    i = 0;
}