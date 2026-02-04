#include <stdlib.h>
#include <stdint.h>

int i;
int16_t *ptr;

static int16_t *ptr_base;
static size_t total_size;

void init_vars() {
    total_size = 1 << 20; // 1MB of data
    ptr_base = aligned_alloc(32, total_size);
    if (!ptr_base) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size / sizeof(int16_t); idx++) {
        ptr_base[idx] = (int16_t)(idx & 0xFFFF);
    }

    ptr = ptr_base;
}

__attribute__((destructor))
static void cleanup() {
    if (ptr_base) {
        free(ptr_base);
    }
}