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
    for (int i = 0; i <= flagIdx && tmp != 0; ++i) {
        if ((tmp & 1) == 0) {
            tmp >>= 1;
            continue;
        }
        metaOffset += kind->metaSize[i];
        tmp >>= 1;
    }
}
