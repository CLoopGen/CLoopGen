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
    for (i = 31; i >= 0; i--) {
        cl->bitmap[i] |= or_with->bitmap[(31 - i)];
    }
}
