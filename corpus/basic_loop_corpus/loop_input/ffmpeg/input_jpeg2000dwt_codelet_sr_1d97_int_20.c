#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *p;
int i0;
int i1;
int i;

static int32_t *allocated_buffer;
static size_t data_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec on typical CPU)

void init_vars() {
    allocated_buffer = (int32_t*)aligned_alloc(32, data_size);
    if (!allocated_buffer) {
        exit(1);
    }

    p = allocated_buffer;
    i0 = 2;
    i1 = (data_size / sizeof(int32_t)) - 4;
}

__attribute__((destructor))
static void cleanup() {
    free(allocated_buffer);
}