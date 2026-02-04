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
    OPJ_UINT32 i;
    OPJ_UINT32 step = 4;
    OPJ_UINT32 unrolled_count = flags_stride / 4;
    opj_flag_t base_val = (1U << 21) | (1U << 24) | (1U << 27) | (1U << 30);
    opj_flag_t offsets[4] = {0, 1U << 20, 1U << 22, 1U << 26};

    for (i = 0; i < unrolled_count; ++i) {
        p[0] = base_val + offsets[0];
        p[1] = base_val + offsets[1];
        p[2] = base_val + offsets[2];
        p[3] = base_val + offsets[3];
        p += step;
    }

    // Handle remainder
    for (i = unrolled_count * 4; i < flags_stride; ++i) {
        *p++ = base_val;
    }
}
