#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int Int32;

Int32 minLen;
Int32 maxLen;
Int32 i;
Int32 *base;
Int32 *limit;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime

    base = (Int32*)calloc(data_size, sizeof(Int32));
    limit = (Int32*)calloc(data_size, sizeof(Int32));

    minLen = 1;
    maxLen = data_size - 2; // ensures limit[i-1] is valid for i up to maxLen
    i = 0;

    // Initialize arrays to avoid undefined behavior
    for (size_t idx = 0; idx < data_size; idx++) {
        base[idx] = idx % 31;
        limit[idx] = idx % 41;
    }
}