#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

int numcols = 1048576;  // ~8MB of data (assuming jpc_fix_t is 8 bytes, two arrays)
int stride = 1;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

void init_vars() {
    size_t total_size = (size_t)numcols * sizeof(jpc_fix_t);

    lptr2 = aligned_alloc(32, total_size);
    hptr2 = aligned_alloc(32, total_size + stride * sizeof(jpc_fix_t));  // account for hptr2[stride]

    if (!lptr2 || !hptr2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int idx = 0; idx < numcols; ++idx) {
        lptr2[idx] = (jpc_fix_t)(idx & 0xFFFFF);
        hptr2[idx] = (jpc_fix_t)((idx + 1) & 0xFFFFF);
    }
    // Ensure hptr2 has valid data at [stride]
    for (int idx = numcols; idx < numcols + stride; ++idx) {
        hptr2[idx] = 0;
    }
}