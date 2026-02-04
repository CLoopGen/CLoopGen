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
    OPJ_UINT32 i, prev_index = 0;
    for (i = 0; i < numcomps_to_decode; i++) {
        OPJ_UINT32 curr_index = comps_indices[i] + (i > 0 ? prev_index : 0); // RAW dependency: current index depends on previous iteration's result
        used_component[curr_index % numcomps_to_decode] = 1; // Introduce loop-carried dependency via index propagation
        prev_index = curr_index; // Carry value across iterations (loop-carried dependency)
    }
}
