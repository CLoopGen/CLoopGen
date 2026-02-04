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
    OPJ_UINT32 temp = v;
    for (x = 0; x < flags_stride; ++x) {
        temp ^= x;           // Introduce RAW dependency: temp depends on previous iteration via x
        *p++ = temp;         // WAW: *p++ and temp are written, but no direct loop-carried dep on p
    }
}
