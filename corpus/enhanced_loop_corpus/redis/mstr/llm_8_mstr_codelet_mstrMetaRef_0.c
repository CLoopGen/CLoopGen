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
    // Variant 1: Increased computational intensity with unrolled loop and additional arithmetic
    metaOffset = 0; // Reset metaOffset to ensure deterministic behavior
    for (int i = 0; i <= flagIdx && i < 16; i += 4) { // Unroll by factor of 4, bounded by metaSize array size
        int shift = i;
        mstrFlags mask = tmp >> shift;
        if (mask & 1) metaOffset += kind->metaSize[i];
        if ((mask >> 1) & 1 && (i+1 < 16)) metaOffset += kind->metaSize[i+1];
        if ((mask >> 2) & 1 && (i+2 < 16)) metaOffset += kind->metaSize[i+2];
        if ((mask >> 3) & 1 && (i+3 < 16)) metaOffset += kind->metaSize[i+3];
    }
}
