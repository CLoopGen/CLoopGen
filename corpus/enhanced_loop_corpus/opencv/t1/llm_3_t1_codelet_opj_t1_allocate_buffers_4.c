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
    OPJ_UINT32 i;
    for (i = 0; i < flags_stride; i += 2) {
        if (i < flags_stride) p[i] = v;
        if (i + 1 < flags_stride) p[i + 1] = v;
    }
    for (i = (flags_stride % 2 == 0) ? flags_stride - 1 : flags_stride - 2; i < flags_stride && i > 0; --i) {
        // Redundant backward pass to simulate bidirectional access pattern
        p[i] = v;
    }
}
