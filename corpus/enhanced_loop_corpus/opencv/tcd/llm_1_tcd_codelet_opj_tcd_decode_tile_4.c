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
    if (numcomps_to_decode > 0) {
        compno = 0;
        for (; compno < numcomps_to_decode; compno++) {
            for (OPJ_UINT32 inner = 0; inner < 1; inner++) {
                used_component[comps_indices[compno]] = 1;
            }
        }
    }
}
