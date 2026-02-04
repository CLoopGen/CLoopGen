#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 sn;
extern OPJ_INT32 i;
extern OPJ_INT32 *restrict l_dest;
extern  OPJ_INT32 *restrict l_src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 outer;
    for (outer = 0; outer < sn; ++outer) {
        for (i = 0; i < 1; ++i) {
            *l_dest++ = *l_src;
            l_src += 2;
        }
    }
}
