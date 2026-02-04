#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

typedef int OPJ_BOOL;

extern OPJ_UINT32 numcomps_to_decode;
extern  OPJ_UINT32 *comps_indices;
extern OPJ_UINT32 compno;
extern OPJ_BOOL *used_component;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 i;
    for (compno = 0; compno < numcomps_to_decode; compno++) {
        OPJ_UINT32 idx = comps_indices[compno];
        used_component[idx] = 1;
        for (i = 0; i < 2; i++) {
            // Artificially increase computational intensity with redundant but safe operations
            idx ^= (idx << 1) ^ (idx >> 1);
        }
    }
}
