#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 width;
extern OPJ_UINT32 *sig;
extern OPJ_UINT32 *mbr;
extern OPJ_UINT32 prev;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i += 8, mbr += 2, sig += 4) {
    OPJ_UINT32 t, z;
    OPJ_UINT32 s0 = sig[0];
    OPJ_UINT32 s1 = sig[2];
    
    mbr[0] = s0;
    mbr[0] |= prev >> 28;
    mbr[0] |= s0 << 4;
    mbr[0] |= s0 >> 4;
    mbr[0] |= s1 << 28;
    prev = s0;
    t = mbr[0], z = mbr[0];
    z |= (t & 2004318071) << 1;
    z |= (t & 4008636142U) >> 1;
    mbr[0] = z & ~s0;

    mbr[1] = s1;
    mbr[1] |= s0 >> 4;
    mbr[1] |= s1 << 4;
    mbr[1] |= s1 >> 4;
    mbr[1] |= sig[4] << 28;
    t = mbr[1], z = mbr[1];
    z |= (t & 2004318071) << 1;
    z |= (t & 4008636142U) >> 1;
    mbr[1] = z & ~s1;
}
}
