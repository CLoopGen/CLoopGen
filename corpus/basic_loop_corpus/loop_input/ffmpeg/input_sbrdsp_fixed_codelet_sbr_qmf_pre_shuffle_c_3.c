#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int *z;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB
    z = (int*)aligned_alloc(32, data_size);
    
    if (!z) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(int); i++) {
        z[i] = rand();
    }
}