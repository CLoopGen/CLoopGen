#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int w2 = 131072; // Size chosen so that loop runs ~0.01 sec (adjustable)
int32_t *b;
int32_t *tmp;

void init_vars() {
    // Allocate arrays with size ensuring no out-of-bounds access
    // Loop accesses b[x + w2] and b[x + w2 - 1], max index is (w2-1) + w2 = 2*w2 - 1
    size_t total_size = 2 * w2 + 10; // Add padding to avoid edge issues

    b = (int32_t*)calloc(total_size, sizeof(int32_t));
    tmp = (int32_t*)calloc(total_size, sizeof(int32_t));

    if (!b || !tmp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize b with non-zero values for meaningful computation
    for (size_t i = 0; i < total_size; i++) {
        b[i] = rand() % 1000;
    }
}