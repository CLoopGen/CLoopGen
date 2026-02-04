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
    tstrip_t i;
    for (i = 0; i < nstrips; i++) {
        tsize_t adjusted_stripbytes = (stripbytes > (tsize_t)local_bytecount) ? local_bytecount : stripbytes;
        newcounts[i] = adjusted_stripbytes;
        newoffsets[i] = local_offset;
        local_offset += adjusted_stripbytes;
        local_bytecount -= adjusted_stripbytes;
    }
    // Eliminate loop-carried dependency on global 'offset' and 'bytecount' until loop end
    offset = local_offset;
    bytecount = local_bytecount;
}
