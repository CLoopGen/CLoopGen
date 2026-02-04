#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int x;
int w2 = 131072;  // Size chosen so that the loop runs long enough (~0.01 sec) and fits within typical cache behavior for benchmarking

int32_t *b;
int32_t *tmp;

static int32_t *b_storage;
static int32_t *tmp_storage;

void init_vars() {
    const size_t data_size = 256 * 1024 * sizeof(int32_t);  // ~1MB total allocation per array to ensure sufficient work
    b_storage = aligned_alloc(32, data_size);
    tmp_storage = aligned_alloc(32, data_size);

    if (!b_storage || !tmp_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(b_storage, 0, data_size);
    memset(tmp_storage, 0, data_size);

    // Initialize tmp with non-trivial values to make computation meaningful
    for (int i = 0; i < 131072 + 2; i++) {
        tmp_storage[i] = (int32_t)(i * 789);
    }

    b = b_storage;
    tmp = tmp_storage;

    x = 0;
}