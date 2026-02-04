#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

#define DATA_SIZE (128 << 20) // 128 MB of data

IDWTELEM *b;
IDWTELEM *temp;
int i;

static IDWTELEM *b_storage;
static IDWTELEM *temp_storage;

void init_vars() {
    b_storage = aligned_alloc(32, DATA_SIZE);
    temp_storage = aligned_alloc(32, DATA_SIZE);

    if (!b_storage || !temp_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    b = b_storage;
    temp = temp_storage;

    // Ensure that the loop can run safely: (i & 30) != 30 and i >= 0
    // We want to start at a value where (i & 30) != 30 and decrease until condition fails
    // The loop stops when (i & 30) == 30. So we need an initial i such that it enters the loop.
    // Choose i such that it's safe for array accesses: b[i + 1], temp[i >> 1], b[i >> 1]
    // Max index used: i+1 must be < allocated size; i>>1 must be valid.

    // Let’s set i to a large even number within bounds.
    // We require: i + 1 < DATA_SIZE / sizeof(IDWTELEM)
    const size_t max_index = (DATA_SIZE / sizeof(IDWTELEM)) - 1;
    i = (max_index > 30) ? ((max_index - 1) & ~1) : 28; // largest even <= max_index-1

    // Adjust i so that (i & 30) != 30 (which is true unless lower 5 bits are 30)
    // If by chance i & 30 == 30, subtract 2 to make it 28
    if ((i & 30) == 30) {
        i -= 2;
    }

    // Initialize arrays to avoid undefined behavior
    for (size_t idx = 0; idx <= max_index; ++idx) {
        b_storage[idx] = (IDWTELEM)(idx & 0xFFFF);
        if (idx < max_index >> 1) {
            temp_storage[idx] = (IDWTELEM)((idx << 1) & 0xFFFF);
        }
    }
}