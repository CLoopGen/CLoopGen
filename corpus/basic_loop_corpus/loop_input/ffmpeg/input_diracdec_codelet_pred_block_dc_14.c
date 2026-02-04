#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union {
    int16_t mv[2][2];
    int16_t dc[3];
};

typedef struct {
    union {
        int16_t mv[2][2];
        int16_t dc[3];
    } u;
    uint8_t ref;
} DiracBlock;

DiracBlock *block;
int stride;
int i;

static DiracBlock *block_storage;
static ptrdiff_t storage_size;

void init_vars() {
    storage_size = (1 << 20) / sizeof(DiracBlock); // ~1MB of data
    block_storage = aligned_alloc(32, storage_size * sizeof(DiracBlock));
    if (!block_storage) exit(1);

    for (ptrdiff_t idx = 0; idx < storage_size; idx++) {
        block_storage[idx].u.dc[0] = rand() % 100;
        block_storage[idx].u.dc[1] = rand() % 100;
        block_storage[idx].u.dc[2] = rand() % 100;
        block_storage[idx].ref = rand() % 2;
    }

    stride = 1024;
    block = block_storage + stride; // ensure block[-stride] is valid
}