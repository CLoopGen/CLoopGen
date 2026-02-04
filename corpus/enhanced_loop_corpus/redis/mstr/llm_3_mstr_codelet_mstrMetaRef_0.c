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
    // Variant 2: Strided memory access (process every second element forward, then remaining)
    int stride = 2;
    // First pass: even indices
    for (int i = 0; i <= flagIdx; i += stride) {
        if ((tmp >> (i / stride)) & 1)
            metaOffset += kind->metaSize[i];
    }
    // Second pass: odd indices
    tmp >>= ((flagIdx + 1 + 1) / 2); // Advance tmp by number of even-indexed checks
    for (int i = 1; i <= flagIdx; i += stride) {
        if (tmp & 1)
            metaOffset += kind->metaSize[i];
        tmp >>= 1;
    }
}
