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
    // Variant 2: Strided memory access - update arrays in reverse order with stride of 1 (reverse traversal)
    for (tstrip_t i = 0; i < nstrips; ++i) {
        tstrip_t rev_index = nstrips - 1 - i;  // Reverse index for strided-like access pattern
        tsize_t current_stripbytes = stripbytes;
        if (current_stripbytes > (tsize_t)bytecount)
            current_stripbytes = bytecount;
        newcounts[rev_index] = current_stripbytes;
        newoffsets[rev_index] = offset;
        offset += current_stripbytes;
        bytecount -= current_stripbytes;
    }
}
