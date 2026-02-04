#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int_fast32_t jpc_fix_t;

int numcols;
int stride;
jpc_fix_t *lptr2;
jpc_fix_t *hptr2;
int i;

static jpc_fix_t *lptr2_base;
static jpc_fix_t *hptr2_base;
static size_t total_size;

void init_vars() {
    // Aim for approximately 64MB of data (32MB for each array)
    // Each jpc_fix_t is at least 4 bytes, so 8M elements gives ~32MB
    total_size = 8000000;
    stride = 1; // Ensure valid access: lptr2[0] and lptr2[stride] are within bounds

    // Adjust numcols so that the loop runs without exceeding array bounds
    // We require: lptr2[i] and lptr2[i + stride] to be valid for i from 0 to numcols-1
    // So we must have at least numcols + stride elements in lptr2 array
    numcols = total_size - stride;

    // Allocate memory for lptr2 and hptr2
    lptr2_base = (jpc_fix_t*)aligned_alloc(32, total_size * sizeof(jpc_fix_t));
    hptr2_base = (jpc_fix_t*)aligned_alloc(32, total_size * sizeof(jpc_fix_t));

    if (!lptr2_base || !hptr2_base) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize arrays to zero
    for (size_t idx = 0; idx < total_size; ++idx) {
        lptr2_base[idx] = 0;
        hptr2_base[idx] = 0;
    }

    // Set pointers to start of arrays
    lptr2 = lptr2_base;
    hptr2 = hptr2_base;
}

// Cleanup function to avoid memory leaks (not required by problem but good practice)
void cleanup_vars() {
    free(lptr2_base);
    free(hptr2_base);
}