#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <malloc.h>

typedef float real_t;

__attribute__((aligned(64))) real_t a[32000];
__attribute__((aligned(64))) real_t b[32000];
__attribute__((aligned(64))) real_t c[32000];
__attribute__((aligned(64))) real_t d[32000];

int *restrict ip;
int n1;
int k;

void init_vars() {
    // Allocate aligned memory for arrays if needed (already declared with alignment)
    // Initialize scalar variables
    n1 = 1;
    k = 0;

    // Allocate and initialize index array ip
    ip = (int*)aligned_alloc(64, 32000 * sizeof(int));
    if (!ip) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize input arrays with meaningful data
    for (int i = 0; i < 32000; i++) {
        a[i] = 1.0f;
        b[i] = 2.0f + i * 0.0001f;
        c[i] = 3.0f + i * 0.0002f;
        d[i] = 4.0f + i * 0.00015f;
        // Ensure that k = ip[i] leads to valid index into c: 32000 - k + 1 - 2 must be in [0, 31999]
        // So k should be in [0, 31999], so set ip[i] to valid offset
        ip[i] = (i + 17) % 31999;  // ensures 32000 - k + 1 - 2 is within bounds
    }
}