#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *res;
int32_t *smp;
int n;
int order;
int i;
int a;

void init_vars() {
    // Set problem size to achieve ~0.01 sec runtime
    // Based on typical CPU speed and loop complexity, use ~64M elements for balance
    n = 64 * 1024 * 1024 / sizeof(int32_t);  // ~256 MB total data
    order = 2;  // Ensure we start after index 1 to allow smp[i-1] access

    // Allocate arrays with padding to prevent out-of-bounds access
    // Loop accesses up to i+1, so need at least n+1 elements
    smp = (int32_t*)aligned_alloc(32, (n + 2) * sizeof(int32_t));
    res = (int32_t*)aligned_alloc(32, (n + 2) * sizeof(int32_t));

    // Initialize arrays with predictable values
    for (int j = 0; j < n + 2; j++) {
        smp[j] = (j & 1) ? 1 : -1;
    }

    // Initialize state variables
    a = 1;
    i = 0;
}