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
    UV base_index;
    U8* bitmap_ptr = ((struct regnode_charclass *)(ret))->bitmap;
    for (value = 0; value < 256; value += 4) {
        base_index = (value >> 3) & 31;
        if ((value) == ' ' || (value) == '\t' || (value) == '\n' || (value) == '\r' || (value) == '\f' || (value) == '\v')
            bitmap_ptr[base_index] |= (1 << (value & 7));
        if (value + 1 < 256 && ((value + 1) == ' ' || (value + 1) == '\t' || (value + 1) == '\n' || (value + 1) == '\r' || (value + 1) == '\f' || (value + 1) == '\v'))
            bitmap_ptr[(value + 1) >> 3] |= (1 << ((value + 1) & 7));
        if (value + 2 < 256 && ((value + 2) == ' ' || (value + 2) == '\t' || (value + 2) == '\n' || (value + 2) == '\r' || (value + 2) == '\f' || (value + 2) == '\v'))
            bitmap_ptr[(value + 2) >> 3] |= (1 << ((value + 2) & 7));
        if (value + 3 < 256 && ((value + 3) == ' ' || (value + 3) == '\t' || (value + 3) == '\n' || (value + 3) == '\r' || (value + 3) == '\f' || (value + 3) == '\v'))
            bitmap_ptr[(value + 3) >> 3] |= (1 << ((value + 3) & 7));
    }
}
