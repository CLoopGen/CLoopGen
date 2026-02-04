#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *p;
int i0;
int i1;
int i;

static int *p_storage;
static size_t data_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec on modern CPU)

void init_vars() {
    p_storage = (int*)aligned_alloc(32, data_size);
    if (!p_storage) {
        exit(1);
    }

    p = p_storage + 1; // Offset to allow access at p[2*i - 1] when i starts near 0

    for (size_t idx = 0; idx < (data_size / sizeof(int)) - 2; idx++) {
        p_storage[idx] = rand();
    }

    i0 = 2; 
    i1 = (data_size / sizeof(int)) - 4; 
}