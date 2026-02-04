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
    OPJ_UINT32 shift_vals[] = {21, 24, 27, 30};
    OPJ_UINT32 base = 0;
    for (x = 0; x < flags_stride; ++x) {
        base = 0;
        for (OPJ_UINT32 i = 0; i < 4; ++i) {
            base |= (1U << shift_vals[i]);
        }
        *p++ = base;
    }
}
