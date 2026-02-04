#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

typedef OPJ_UINT32 opj_flag_t;

extern OPJ_UINT32 flags_stride;
extern opj_flag_t *p;
extern OPJ_UINT32 x;
extern OPJ_UINT32 v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 step = 2;
    for (x = 0; x < flags_stride; x += step) {
        *p++ = v;
        if (x + 1 < flags_stride) {
            *p++ = v;
        }
    }
}
