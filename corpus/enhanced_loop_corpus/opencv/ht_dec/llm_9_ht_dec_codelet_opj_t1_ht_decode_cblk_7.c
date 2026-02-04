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
for (i = 0; i < width; i += 4 , mbr++ , sig++) {
    OPJ_UINT32 t, z;
    // Reduced arithmetic intensity: removed one shift and simplified dependencies
    mbr[0] = sig[0];
    mbr[0] |= prev >> 28;
    mbr[0] |= sig[0] << 4;
    // Removed: mbr[0] |= sig[0] >> 4;
    mbr[0] |= sig[1] << 28;
    prev = sig[0];
    t = mbr[0];
    z = t;
    // Removed one of the bit manipulation operations to reduce complexity
    z |= (t & 2004318071) << 1;
    // Removed: z |= (t & 4008636142U) >> 1;
    mbr[0] = z & ~sig[0];
}
}
