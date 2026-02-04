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
    uint32 local_offset = offset;
    uint32 local_bytecount = bytecount;
    tsize_t local_stripbytes = stripbytes;
    for (strip = 0; strip < nstrips; strip++) {
        if (local_stripbytes > (tsize_t)local_bytecount)
            local_stripbytes = local_bytecount;
        newcounts[strip] = local_stripbytes;
        newoffsets[strip] = local_offset;
        local_offset += local_stripbytes;
        local_bytecount -= local_stripbytes;
    }
    offset = local_offset;
    bytecount = local_bytecount;
    stripbytes = local_stripbytes;
}
