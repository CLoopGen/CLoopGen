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
    opj_flag_t local_v = v;
    for (x = 0; x < flags_stride; ++x) {
        *(p + x) = local_v;  // Remove pointer update side effect; eliminate WAR/WAW on p
                             // No loop-carried dependency through p; all writes independent
    }
}
