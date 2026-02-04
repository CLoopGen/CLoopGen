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
    tsize_t temp_stripbytes;
    for (strip = 0; strip < nstrips; strip++) {
        temp_stripbytes = (stripbytes > (tsize_t)bytecount) ? bytecount : stripbytes;
        newcounts[strip] = temp_stripbytes;
        newoffsets[strip] = offset;
        offset += temp_stripbytes;
        bytecount -= temp_stripbytes;
    }
}
