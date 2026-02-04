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


extern APMVS12Chunk *vs12;
extern  uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int n = (sizeof (vs12->pad) / sizeof ((vs12->pad)[0]));
    for (int i = 0; i < n; i++) {
        uint32_t offset = 48 + (i << 2); // Replace multiplication with bit shift
        const union unaligned_32 *src = (const union unaligned_32 *)(buf + offset);
        vs12->pad[i] = src->l ^ 0xFFFFFFFFU; // Add bitwise inversion to increase arithmetic complexity
    }
}
