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
    // Variant 1: Consecutive memory access using pointer arithmetic (forward traversal)
    char *bm_cl = cl->bitmap;
    char *bm_or = or_with->bitmap;
    for (i = 0; i < 32; i++) {
        *bm_cl++ |= *bm_or++;
    }
}
