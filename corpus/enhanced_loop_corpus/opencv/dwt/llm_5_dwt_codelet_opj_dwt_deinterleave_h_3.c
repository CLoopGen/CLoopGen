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
    for (i = 0; i < dn; ++i) {
        if ((i & 1) == 0) {
            *l_dest++ = *l_src;
            l_src += 2;
        } else {
            *l_dest++ = *l_src + 1;
            l_src += 2;
        }
    }
}
