#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

typedef OPJ_UINT32 opj_flag_t;

extern OPJ_UINT32 flags_stride;
extern opj_flag_t *p;
extern OPJ_UINT32 x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 i, j;
    OPJ_UINT32 block_size = 16;
    OPJ_UINT32 num_blocks = (flags_stride + block_size - 1) / block_size;

    for (i = 0; i < num_blocks; ++i) {
        for (j = 0; j < block_size; ++j) {
            x = i * block_size + j;
            if (x >= flags_stride) return;
            *p++ = ((1U << 21) | (1U << 24) | (1U << 27) | (1U << 30));
        }
    }
}
