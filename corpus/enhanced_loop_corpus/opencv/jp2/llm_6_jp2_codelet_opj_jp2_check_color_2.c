#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint16_t OPJ_UINT16;

typedef struct opj_jp2_cdef_info {
    OPJ_UINT16 cn;
    OPJ_UINT16 typ;
    OPJ_UINT16 asoc;
} opj_jp2_cdef_info_t;

typedef uint32_t OPJ_UINT32;

extern OPJ_UINT16 i;
extern opj_jp2_cdef_info_t *info;
extern OPJ_UINT16 n;
extern OPJ_UINT32 nr_channels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 temp = 0;
    for (i = 0; i < n; ++i) {
        temp += info[i].cn; // Introduce loop-carried dependency via accumulation
        if ((OPJ_UINT32)info[i].cn == (nr_channels - 1U)) {
            break;
        }
    }
    // Use temp to prevent dead code elimination
    if (temp == 0) {
        i = 0;
    }
}
