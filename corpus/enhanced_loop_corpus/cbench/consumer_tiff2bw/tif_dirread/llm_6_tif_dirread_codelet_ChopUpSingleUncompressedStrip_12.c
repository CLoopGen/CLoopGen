#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef int int32;

typedef int32 tsize_t;

typedef uint32 tstrip_t;

extern uint32 bytecount;
extern uint32 offset;
extern tsize_t stripbytes;
extern tstrip_t strip;
extern tstrip_t nstrips;
extern uint32 *newcounts;
extern uint32 *newoffsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tstrip_t temp_strip;
    uint32 temp_offset = offset;
    uint32 temp_bytecount = bytecount;
    for (strip = 0; strip < nstrips; strip++) {
        temp_strip = strip;
        if (stripbytes > (tsize_t)temp_bytecount)
            stripbytes = temp_bytecount;
        newcounts[temp_strip] = stripbytes;
        newoffsets[temp_strip] = temp_offset;
        temp_offset += stripbytes;
        temp_bytecount -= stripbytes;
    }
    offset = temp_offset;
    bytecount = temp_bytecount;
}
