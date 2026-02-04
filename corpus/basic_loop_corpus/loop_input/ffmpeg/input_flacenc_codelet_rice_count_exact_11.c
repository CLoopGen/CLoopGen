#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *res;
int n;
int k;
int i;
uint64_t count;

void init_vars() {
    n = 64 * 1024 * 1024; // ~256MB of int32_t data (64M elements)
    res = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));
    if (!res) {
        exit(1);
    }
    
    // Initialize array with non-zero pattern to ensure meaningful computation
    for (int j = 0; j < n; j++) {
        res[j] = (int32_t)(j ^ 0xdeadbeef);
    }

    k = 5; // arbitrary shift value in valid range (0 <= k < 32)
    count = 0;
}