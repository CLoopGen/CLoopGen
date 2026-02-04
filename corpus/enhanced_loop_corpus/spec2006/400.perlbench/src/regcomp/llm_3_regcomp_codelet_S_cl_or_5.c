#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef unsigned short U16;

typedef unsigned int U32;

struct regnode_charclass_class {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
    char classflags[4];
};


extern struct regnode_charclass_class *cl;
extern struct regnode_charclass_class *or_with;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with a fixed stride of 2, processing every other element in reverse order
    int stride = 2;
    for (i = 2; i >= 0; i -= stride) {
        cl->classflags[i] |= or_with->classflags[i];
        if (i + 1 < 4) {
            cl->classflags[i + 1] |= or_with->classflags[i + 1];
        }
    }
}
