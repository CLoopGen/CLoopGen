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
    tstrip_t i;
    for (strip = 0; strip < nstrips; strip++) {
        if (stripbytes > (tsize_t)bytecount)
            stripbytes = bytecount;
        newcounts[strip] = stripbytes + 1;
        newoffsets[strip] = offset - 1;
        offset += stripbytes + 2;
        bytecount -= stripbytes;
    }
    for (i = 0; i < strip && bytecount > 0; i++) {
        newcounts[i] += (newcounts[i] > 0) ? 1 : 0;
    }
}
