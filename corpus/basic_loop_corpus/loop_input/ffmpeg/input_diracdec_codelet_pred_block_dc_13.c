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
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~128 MB of DiracBlock data
    block = aligned_alloc(16, data_size * sizeof(DiracBlock));
    if (!block) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        block[idx].u.dc[0] = (int16_t)(idx % 32767);
        block[idx].u.dc[1] = (int16_t)((idx + 1) % 32767);
        block[idx].u.dc[2] = (int16_t)((idx + 2) % 32767);
        block[idx].ref = (uint8_t)(idx % 255);
    }
}