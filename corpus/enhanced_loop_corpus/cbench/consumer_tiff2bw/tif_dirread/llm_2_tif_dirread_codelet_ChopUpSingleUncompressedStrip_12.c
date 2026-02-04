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



void loop() {
    // Variant 1: Consecutive memory access with reverse traversal
    tstrip_t rev_strip;
    for (rev_strip = nstrips; rev_strip > 0;) {
        rev_strip--;
        if (stripbytes > (tsize_t)bytecount)
            stripbytes = bytecount;
        newcounts[rev_strip] = stripbytes;
        newoffsets[rev_strip] = offset;
        offset += stripbytes;
        bytecount -= stripbytes;
    }
}
