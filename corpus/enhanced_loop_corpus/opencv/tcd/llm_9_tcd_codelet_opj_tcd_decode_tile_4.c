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
    // Reduce effective trip count by processing every other element, then compensate with dual assignments
    for (compno = 0; compno < numcomps_to_decode; compno += 2) {
        OPJ_UINT32 idx1 = comps_indices[compno];
        used_component[idx1] = 1;

        if (compno + 1 < numcomps_to_decode) {
            OPJ_UINT32 idx2 = comps_indices[compno + 1];
            used_component[idx2] = 1;
        }
    }
}
