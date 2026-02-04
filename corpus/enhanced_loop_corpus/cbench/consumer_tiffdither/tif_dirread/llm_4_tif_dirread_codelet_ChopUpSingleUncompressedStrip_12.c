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
    for (strip = 0; strip < nstrips; strip++) {
        if (bytecount == 0) {
            newcounts[strip] = 0;
            newoffsets[strip] = offset;
            continue;
        }
        if (stripbytes > (tsize_t)bytecount)
            stripbytes = bytecount;
        newcounts[strip] = stripbytes;
        newoffsets[strip] = offset;
        offset += stripbytes;
        bytecount -= stripbytes;
    }
}
