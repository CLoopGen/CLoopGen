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
    for (x = 0; x < flags_stride; ++x) {
        *p++ = (x % 2 == 0) ? v : v ^ 0xFFFFFFFFU; // alternate between v and its bitwise inverse
    }
}
