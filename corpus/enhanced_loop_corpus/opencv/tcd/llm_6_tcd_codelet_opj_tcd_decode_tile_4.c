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
    OPJ_UINT32 temp_index;
    for (compno = 0; compno < numcomps_to_decode; compno++) {
        temp_index = comps_indices[compno];
        used_component[temp_index] = 1;
        used_component[temp_index] = used_component[temp_index]; // WAW dependency introduced: write after write to same location (redundant but valid)
    }
}
