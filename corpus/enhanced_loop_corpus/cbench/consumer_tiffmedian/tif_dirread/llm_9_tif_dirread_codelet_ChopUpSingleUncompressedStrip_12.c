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
    tstrip_t step = 2;
    tstrip_t limit = (nstrips + 1) / 2;
    for (strip = 0; strip < limit; strip++) {
        tstrip_t idx1 = strip * step;
        tstrip_t idx2 = idx1 + 1;
        uint32 adjusted_bytes = (stripbytes > bytecount) ? bytecount : stripbytes;

        newcounts[idx1] = adjusted_bytes;
        newoffsets[idx1] = offset;
        offset += adjusted_bytes;
        bytecount -= adjusted_bytes;

        if (idx2 < nstrips && bytecount > 0) {
            uint32 adjusted_bytes2 = (stripbytes > bytecount) ? bytecount : stripbytes;
            newcounts[idx2] = adjusted_bytes2;
            newoffsets[idx2] = offset;
            offset += adjusted_bytes2;
            bytecount -= adjusted_bytes2;
        }
    }
}
