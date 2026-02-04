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
    // Variant 1: Consecutive memory access with forward traversal (original order preserved)
    for (tstrip_t i = 0; i < nstrips; ++i) {
        tsize_t current_stripbytes = stripbytes;
        if (current_stripbytes > (tsize_t)bytecount)
            current_stripbytes = bytecount;
        newcounts[i] = current_stripbytes;
        newoffsets[i] = offset;
        offset += current_stripbytes;
        bytecount -= current_stripbytes;
    }
}
