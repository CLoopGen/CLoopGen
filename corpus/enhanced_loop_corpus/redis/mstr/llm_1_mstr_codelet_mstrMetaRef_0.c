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
    for (int i = 0; i <= flagIdx; ++i) {
        for (int j = i; j <= i; ++j) { // Artificially nested, depth increased by one level
            if (tmp & 1)
                metaOffset += kind->metaSize[i];
            tmp >>= 1;
        }
    }
}
