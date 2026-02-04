#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w2 = 1024;
int x = 0;

static int32_t *b_storage = NULL;
static int32_t *tmp_storage = NULL;
int32_t *b = NULL;
int32_t *tmp = NULL;

void init_vars() {
    const size_t data_size = 1 << 20; // ~4MB total memory (scales well, avoids overflow)

    if (b_storage != NULL) return; // prevent double initialization

    b_storage = aligned_alloc(32, sizeof(int32_t) * data_size);
    tmp_storage = aligned_alloc(32, sizeof(int32_t) * data_size);

    if (!b_storage || !tmp_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        b_storage[i] = rand() % 1000;
        tmp_storage[i] = 0;
    }

    w2 = 1024; // Set w2 such that w2*w2 fits in allocated space and allows stencil access
    b = b_storage;
    tmp = tmp_storage;
}