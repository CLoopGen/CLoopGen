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
    for (int i = 0; i <= flagIdx; ++i) {
        if (localTmp & 1)
            metaOffset += kind->metaSize[flagIdx - i];  // Reverse access order: introduces WAR/WAW if called repeatedly
        localTmp >>= 1;
    }
}
