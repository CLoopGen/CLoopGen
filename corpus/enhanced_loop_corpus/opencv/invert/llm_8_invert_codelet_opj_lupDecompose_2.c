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
    OPJ_UINT32 step = 1;
    for (i = 0; i < nb_compo; i += step) {
        *tmpPermutations++ = i * 2 + 1;
    }
}
