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



void loop(){
    // Variant 1: Introduce loop-carried WAW dependency by splitting the operation into two dependent stages
    // First pass: copy and_with->bitmap to cl->bitmap
    for (i = 0; i < 32; i++)
        cl->bitmap[i] = and_with->bitmap[i];

    // Second pass: apply bitwise AND with original cl->bitmap, creating a write-after-write (WAW) hazard
    // This introduces a loop-carried dependence where each write in the first loop must complete before the second
    for (i = 0; i < 32; i++)
        cl->bitmap[i] &= and_with->bitmap[i];
}
