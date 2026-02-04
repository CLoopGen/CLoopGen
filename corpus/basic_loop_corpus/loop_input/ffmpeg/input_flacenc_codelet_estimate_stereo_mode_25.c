#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *left_ch;
int32_t *right_ch;
int n;
int i;
int32_t lt;
int32_t rt;
uint64_t sum[4];

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256MB total for both arrays
    n = data_size / sizeof(int32_t);

    left_ch = (int32_t*)aligned_alloc(32, data_size);
    right_ch = (int32_t*)aligned_alloc(32, data_size);

    if (!left_ch || !right_ch) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize arrays with pseudo-random data for realistic computation
    srand((unsigned int)time(NULL));
    for (int j = 0; j < n; j++) {
        left_ch[j] = (int32_t)(rand() % 2000 - 1000);
        right_ch[j] = (int32_t)(rand() % 2000 - 1000);
    }

    // Ensure first two elements are valid for loop start at i=2
    // No special initialization needed beyond allocation

    // Initialize sum array to zero
    sum[0] = 0;
    sum[1] = 0;
    sum[2] = 0;
    sum[3] = 0;

    // Initialize lt and rt to zero
    lt = 0;
    rt = 0;
}