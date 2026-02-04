#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *bounding_values;
int16_t temp_16[8];
int temp_32[8];

void init_vars() {
    // Allocate bounding_values as an array of int pointers, but since it's used as
    // a lookup table for indices from temp_16, we interpret it as a large array of int.
    // We allocate 65536 elements to cover full range of int16_t if needed, but initialize safe subset.

    // Since temp_16[i] is int16_t, its value can be in range [-32768, 32767]. To avoid segfault,
    // we must ensure that all values in temp_16 are valid indices into bounding_values.
    // So we'll restrict temp_16 to [0, 999] and make bounding_values of size 1000.

    const int table_size = 1000;
    bounding_values = (int*)calloc(table_size, sizeof(int));
    if (!bounding_values) exit(1);

    // Initialize temp_16 with safe indices in [0, table_size - 1]
    for (int i = 0; i < 8; i++) {
        temp_16[i] = i * 100;  // e.g., 0, 100, 200, ..., 700 -> all < 1000
    }

    // Optionally initialize temp_32 to zero
    for (int i = 0; i < 8; i++) {
        temp_32[i] = 0;
    }
}