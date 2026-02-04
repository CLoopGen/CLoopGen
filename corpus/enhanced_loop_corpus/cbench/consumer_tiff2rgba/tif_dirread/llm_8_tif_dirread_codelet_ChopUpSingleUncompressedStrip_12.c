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
    for (i = 0; i < nstrips; i += 2) {
        if (i >= nstrips) break;
        if (stripbytes > (tsize_t)bytecount)
            stripbytes = bytecount;
        newcounts[i] = stripbytes;
        newoffsets[i] = offset;
        offset += stripbytes;
        bytecount -= stripbytes;

        if (i + 1 < nstrips) {
            uint32 next_stripbytes = stripbytes;
            if (next_stripbytes > bytecount)
                next_stripbytes = bytecount;
            newcounts[i+1] = next_stripbytes;
            newoffsets[i+1] = offset;
            offset += next_stripbytes;
            bytecount -= next_stripbytes;
        }
    }
}
