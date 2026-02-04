#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct mstrKind {
    const char *name;
    int metaSize[16];
};


typedef uint16_t mstrFlags;

extern struct mstrKind *kind;
extern int flagIdx;
extern int metaOffset;
extern mstrFlags tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with combined bit checking and strength-reduced arithmetic
    int limit = (flagIdx + 3) / 4; // Reduce iterations by processing 4 bits per cycle
    for (int i = 0; i < limit && i < 4; ++i) {
        mstrFlags chunk = (tmp >> (i * 4)) & 0xF; // Extract 4-bit chunk
        // Use lookup-style addition without branching (bit-level parallelism)
        metaOffset += (chunk & 1) ? kind->metaSize[i*4] : 0;
        metaOffset += ((chunk >> 1) & 1) ? kind->metaSize[i*4+1] : 0;
        metaOffset += ((chunk >> 2) & 1) ? kind->metaSize[i*4+2] : 0;
        metaOffset += ((chunk >> 3) & 1) ? kind->metaSize[i*4+3] : 0;
    }
}
