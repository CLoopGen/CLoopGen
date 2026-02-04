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
extern struct regnode_charclass_class *and_with;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 4 (processes every 4th element in each iteration)
    int stride = 4;
    for (i = 0; i < 32; i += stride) {
        cl->bitmap[i] &= and_with->bitmap[i];
        if (i + 1 < 32) cl->bitmap[i + 1] &= and_with->bitmap[i + 1];
        if (i + 2 < 32) cl->bitmap[i + 2] &= and_with->bitmap[i + 2];
        if (i + 3 < 32) cl->bitmap[i + 3] &= and_with->bitmap[i + 3];
    }
}
