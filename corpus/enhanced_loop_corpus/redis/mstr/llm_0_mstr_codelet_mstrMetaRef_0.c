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
        for (int j = 0; j < 1; ++j) { // Nested inner loop with fixed single iteration
            if (tmp & 1)
                metaOffset += kind->metaSize[i];
            tmp >>= 1;
        }
    }
}
