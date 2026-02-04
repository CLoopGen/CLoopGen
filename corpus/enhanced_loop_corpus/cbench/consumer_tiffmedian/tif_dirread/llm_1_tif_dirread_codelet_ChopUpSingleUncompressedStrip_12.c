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
    tstrip_t outer;
    tstrip_t inner;
    for (outer = 0; outer < nstrips; outer++) {
        for (inner = 0; inner < 1; inner++) {
            strip = outer;
            if (stripbytes > (tsize_t)bytecount)
                stripbytes = bytecount;
            newcounts[strip] = stripbytes;
            newoffsets[strip] = offset;
            offset += stripbytes;
            bytecount -= stripbytes;
        }
    }
}
