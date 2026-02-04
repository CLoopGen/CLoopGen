#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct APMState {
    int32_t has_saved;
    int32_t predictor_r;
    int32_t step_index_r;
    int32_t saved_r;
    int32_t predictor_l;
    int32_t step_index_l;
    int32_t saved_l;
} APMState;

typedef struct APMVS12Chunk {
    uint32_t magic;
    uint32_t file_size;
    uint32_t data_size;
    uint32_t unk1;
    uint32_t unk2;
    APMState state;
    uint32_t pad[7];
} APMVS12Chunk;

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

APMVS12Chunk *vs12;
uint8_t *buf;

void init_vars() {
    const size_t buf_size = 1024 * 1024; // ~1MB to ensure non-trivial loop runtime
    buf = (uint8_t*)calloc(buf_size, sizeof(uint8_t));
    if (!buf) exit(1);

    vs12 = (APMVS12Chunk*)calloc(1, sizeof(APMVS12Chunk));
    if (!vs12) exit(1);

    for (int i = 0; i < 7; i++) {
        size_t offset = 48 + i * 4;
        if (offset + 4 <= buf_size) {
            ((uint32_t*)(buf + offset))[0] = 0xDEADBEEF + i;
        }
    }
}