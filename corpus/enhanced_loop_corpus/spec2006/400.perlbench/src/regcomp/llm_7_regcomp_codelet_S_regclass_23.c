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
    UV local_value;
    char *bm = ((struct regnode_charclass *)(ret))->bitmap;
    for (local_value = 0; local_value < 256; local_value++) {
        value = local_value;
        if ((((value) >= 'A' && (value) <= 'Z') || ((value) >= 'a' && (value) <= 'z'))) {
            UV offset = (value >> 3) & 31;
            U8 bit = (1 << (value & 7));
            bm[offset] |= bit;
        }
    }
}
