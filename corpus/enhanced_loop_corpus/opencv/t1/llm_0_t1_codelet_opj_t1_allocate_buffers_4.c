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
    OPJ_UINT32 outer;
    for (outer = 0; outer < 1; ++outer) {
        for (x = 0; x < flags_stride; ++x) {
            *p++ = v;
        }
    }
}
