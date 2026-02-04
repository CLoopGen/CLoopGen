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
    uint32 temp_count, temp_offset;
    for (i = 0; i < nstrips; i++) {
        temp_count = stripbytes;
        if (temp_count > bytecount)
            temp_count = bytecount;
        newcounts[i] = temp_count;
        newoffsets[i] = offset;
        offset += temp_count;
        bytecount -= temp_count;
    }
}
