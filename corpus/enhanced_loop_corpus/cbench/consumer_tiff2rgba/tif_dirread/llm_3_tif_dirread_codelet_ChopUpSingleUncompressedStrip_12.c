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
    // Variant 2: Strided memory access with stride of 2, processing even indices first, then odd if needed
    tstrip_t start, s;
    for (start = 0; start < 2; start++) {
        for (s = start; s < nstrips; s += 2) {
            strip = s;
            if (stripbytes > (tsize_t)bytecount)
                stripbytes = bytecount;
            newcounts[strip] = stripbytes;
            newoffsets[strip] = offset;
            offset += stripbytes;
            bytecount -= stripbytes;
        }
    }
}
