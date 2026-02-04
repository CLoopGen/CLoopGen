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
static size_t total_blocks;

void init_vars() {
    total_blocks = (1 << 20) / sizeof(DiracBlock); // ~1MB of data
    if (total_blocks < 4) total_blocks = 4;

    block_storage = calloc(total_blocks, sizeof(DiracBlock));
    if (!block_storage) {
        fprintf(stderr, "Failed to allocate block storage\n");
        exit(1);
    }

    block = &block_storage[1 + total_blocks/2]; 
    stride = 1;

    for (size_t idx = 0; idx < total_blocks; ++idx) {
        block_storage[idx].u.dc[0] = (int16_t)(idx % 32767);
        block_storage[idx].u.dc[1] = (int16_t)((idx * 3) % 32767);
        block_storage[idx].u.dc[2] = (int16_t)((idx * 7) % 32767);
        block_storage[idx].ref = (uint8_t)(idx % 255);
    }
}