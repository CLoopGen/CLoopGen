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
    OPJ_UINT32 value = (1U << 21) | (1U << 24) | (1U << 27) | (1U << 30);
    for (i = 0; i < flags_stride; ++i) {
        p[i] = value;
    }
}
