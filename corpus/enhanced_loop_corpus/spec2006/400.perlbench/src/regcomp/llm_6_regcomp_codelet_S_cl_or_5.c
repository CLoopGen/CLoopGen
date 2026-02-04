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



void loop() {
    // Variant 1: Introduce loop-carried WAW dependency by splitting the operation and reordering writes
    // This creates a Write-After-Write dependency across iterations by writing to a temporary array first,
    // then copying back — introducing artificial WAW hazard.
    char temp_classflags[4];
    for (i = 0; i < 4; i++) {
        temp_classflags[i] = cl->classflags[i] | or_with->classflags[i];
    }
    for (i = 0; i < 4; i++) {
        cl->classflags[i] = temp_classflags[i];  // WAW: Writing again after prior write in separate loop
    }
}
