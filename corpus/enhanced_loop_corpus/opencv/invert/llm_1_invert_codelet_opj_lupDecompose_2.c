#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 nb_compo;
extern OPJ_UINT32 *tmpPermutations;
extern OPJ_UINT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 outer_i;
    for (outer_i = 0; outer_i < nb_compo; ++outer_i) {
        i = outer_i;
        *tmpPermutations++ = i;
    }
}
