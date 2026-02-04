#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;

int32 *active;
int32 i;
int32 c;

static int32 *active_storage;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    active_storage = (int32*)calloc(data_size, sizeof(int32));
    
    if (!active_storage) {
        exit(1);
    }

    // Fill with non-negative values except for the last element
    for (size_t idx = 0; idx < data_size - 1; idx++) {
        active_storage[idx] = (int32)(idx & 0x7FFFFFFF); // Non-negative
    }
    // Terminate loop condition
    active_storage[data_size - 1] = -1;

    active = active_storage;
    i = 0;
    c = 0;
}