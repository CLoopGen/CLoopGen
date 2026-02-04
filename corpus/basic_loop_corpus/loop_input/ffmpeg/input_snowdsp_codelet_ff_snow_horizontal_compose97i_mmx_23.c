#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *b;
IDWTELEM *temp;
int i;

#define DATA_SIZE (128 << 20) // 128 MB of data

static IDWTELEM *b_storage;
static IDWTELEM *temp_storage;

void init_vars() {
    b_storage = aligned_alloc(16, DATA_SIZE * sizeof(IDWTELEM));
    temp_storage = aligned_alloc(16, DATA_SIZE * sizeof(IDWTELEM));

    if (!b_storage || !temp_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        b_storage[idx] = (IDWTELEM)(idx & 0xFFFF);
        temp_storage[idx] = (IDWTELEM)((idx ^ 0x5555) & 0xFFFF);
    }

    b = b_storage;
    temp = temp_storage;
    i = (DATA_SIZE >> 1) - ((DATA_SIZE >> 1) % 32); // Ensure i is multiple of 32 and valid for loop
}