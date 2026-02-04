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
    OPJ_UINT32 x_outer;
    for (x_outer = 0; x_outer < flags_stride / 2 + (flags_stride % 2); ++x_outer) {
        for (x = 0; x < 2 && (x_outer * 2 + x) < flags_stride; ++x) {
            *p++ = ((1U << 21) | (1U << 24) | (1U << 27) | (1U << 30));
        }
    }
}
