#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 dn;
extern OPJ_INT32 i;
extern OPJ_INT32 *restrict l_dest;
extern  OPJ_INT32 *restrict l_src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 j;
    for (j = 0; j < dn; ++j) {
        l_dest[j] = l_src[2 * j];
    }
}
