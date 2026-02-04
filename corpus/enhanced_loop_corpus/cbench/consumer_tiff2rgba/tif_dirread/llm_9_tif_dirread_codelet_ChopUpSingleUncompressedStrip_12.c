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
    tstrip_t stride = 4;
    tstrip_t limit = (nstrips + stride - 1) / stride * stride;
    for (strip = 0; strip < limit; strip++) {
        if (strip >= nstrips) continue;
        uint32 current_bytes = (stripbytes > (tsize_t)bytecount) ? bytecount : stripbytes;
        newcounts[strip] = current_bytes;
        newoffsets[strip] = offset;
        offset += current_bytes;
        bytecount -= current_bytes;
    }
}
