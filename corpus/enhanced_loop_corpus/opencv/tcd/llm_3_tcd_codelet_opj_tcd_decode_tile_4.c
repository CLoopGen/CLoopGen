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
    OPJ_UINT32 stride = 2;
    OPJ_UINT32 i;
    for (compno = 0; compno < numcomps_to_decode; compno += stride) {
        used_component[comps_indices[compno]] = 1;
        if (compno + 1 < numcomps_to_decode) {
            used_component[comps_indices[compno + 1]] = 1;
        }
    }
}
