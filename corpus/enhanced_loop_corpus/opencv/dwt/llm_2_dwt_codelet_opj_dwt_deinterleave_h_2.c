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
for (i = 0; i < sn; ++i) {
    l_dest[i] = l_src[i * 2];
}
}
