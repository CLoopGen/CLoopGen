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
for (i = 0; i < width; i += 16 , mbr += 2 , sig += 2) {
    OPJ_UINT32 t0, z0, t1, z1;
    
    // First unrolled iteration (i+0)
    mbr[0] = sig[0];
    mbr[0] |= prev >> 28;
    mbr[0] |= sig[0] << 4;
    mbr[0] |= sig[0] >> 4;
    mbr[0] |= sig[1] << 28;
    t0 = mbr[0];
    z0 = t0;
    z0 |= (t0 & 2004318071) << 1;
    z0 |= (t0 & 4008636142U) >> 1;
    mbr[0] = z0 & ~sig[0];
    prev = sig[0];

    // Second unrolled iteration (i+1)
    mbr[1] = sig[1];
    mbr[1] |= prev >> 28;
    mbr[1] |= sig[1] << 4;
    mbr[1] |= sig[1] >> 4;
    mbr[1] |= sig[2] << 28;
    t1 = mbr[1];
    z1 = t1;
    z1 |= (t1 & 2004318071) << 1;
    z1 |= (t1 & 4008636142U) >> 1;
    mbr[1] = z1 & ~sig[1];
    prev = sig[1];
}
}
