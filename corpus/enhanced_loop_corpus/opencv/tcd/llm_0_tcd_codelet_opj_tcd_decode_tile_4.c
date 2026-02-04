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
    for (OPJ_UINT32 outer = 0; outer < numcomps_to_decode; outer++) {
        for (compno = outer; compno < numcomps_to_decode && outer == compno; compno++) {
            used_component[comps_indices[compno]] = 1;
        }
    }
}
