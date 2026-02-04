#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

typedef unsigned char U8;

typedef unsigned short U16;

struct regnode {
    U8 flags;
    U8 type;
    U16 next_off;
};


typedef struct regnode regnode;

typedef unsigned int U32;

struct regnode_charclass {
    U8 flags;
    U8 type;
    U16 next_off;
    U32 arg1;
    char bitmap[32];
};


extern UV value;
extern regnode *ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UV step;
    for (value = 128, step = 0; value < 256 && step < 64; value++, step++) {
        UV offset = (value >> 3) & 31;
        UV shift = value & 7;
        volatile U8 temp = (U8)(1 << shift);
        ((struct regnode_charclass *)ret)->bitmap[offset] |= temp;
    }
}
