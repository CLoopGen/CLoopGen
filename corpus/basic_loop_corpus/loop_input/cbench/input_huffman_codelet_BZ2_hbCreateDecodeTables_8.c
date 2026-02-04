#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int Int32;

Int32 *base;
Int32 i;

void init_vars() {
    const size_t data_size = 1 << 24; // ~64 million elements, ~256 MB for int
    base = (Int32*)calloc(data_size, sizeof(Int32));
    if (!base) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    // Initialize with non-zero values to make the loop meaningful
    for (size_t idx = 0; idx < data_size; idx++) {
        base[idx] = 1;
    }
}