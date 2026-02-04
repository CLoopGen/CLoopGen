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
    mstrFlags localTmp = tmp;
    int localOffset = metaOffset;
    for (int i = 0; i <= flagIdx; ++i) {
        int bit = localTmp & 1;
        localTmp >>= 1;
        if (bit)
            localOffset += kind->metaSize[i];
    }
    metaOffset = localOffset;
}
