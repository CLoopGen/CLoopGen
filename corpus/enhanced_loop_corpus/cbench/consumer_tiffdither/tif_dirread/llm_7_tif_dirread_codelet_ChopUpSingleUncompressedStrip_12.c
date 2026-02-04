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
    tstrip_t strip_rev;
    uint32 local_bytecount = bytecount;
    uint32 local_offset = offset;
    for (strip_rev = 0; strip_rev < nstrips; strip_rev++) {
        uint32 current_stripbytes = stripbytes;
        if (current_stripbytes > local_bytecount)
            current_stripbytes = local_bytecount;
        newcounts[strip_rev] = current_stripbytes;
        newoffsets[strip_rev] = local_offset;
        local_offset += current_stripbytes;
        local_bytecount -= current_stripbytes;
    }
    offset = local_offset;
    bytecount = local_bytecount;
}
