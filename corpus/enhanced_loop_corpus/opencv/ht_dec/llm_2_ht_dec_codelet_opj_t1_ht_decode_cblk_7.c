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
for (i = 0; i < width; i += 8, mbr++, sig++) {
    OPJ_UINT32 t, z;
    OPJ_UINT32 *sig_offset = &sig[0];
    OPJ_UINT32 *mbr_offset = &mbr[0];

    mbr_offset[0] = sig_offset[0];
    mbr_offset[0] |= prev >> 28;
    mbr_offset[0] |= sig_offset[0] << 4;
    mbr_offset[0] |= sig_offset[0] >> 4;
    mbr_offset[0] |= sig_offset[1] << 28;
    prev = sig_offset[0];
    t = mbr_offset[0], z = mbr_offset[0];
    z |= (t & 2004318071) << 1;
    z |= (t & 4008636142U) >> 1;
    mbr_offset[0] = z & ~sig_offset[0];
}
}
