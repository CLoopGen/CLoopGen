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
    OPJ_UINT32 i, j;
    for (i = 0; i < flags_stride; ++i) {
        for (j = 0; j < 1; ++j) {
            x = i;
            *p++ = v;
        }
    }
}
