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
    for (value = 0; value < 256; value += 2) {
        UV index = value >> 3;
        UV bit = value & 7;
        U8 mask = (U8)(1 << bit);
        ((struct regnode_charclass *)ret)->bitmap[index & 31] |= mask;
        if (value + 1 < 256) {
            bit = (value + 1) & 7;
            mask = (U8)(1 << bit);
            ((struct regnode_charclass *)ret)->bitmap[(index + (bit == 0 ? 1 : 0)) & 31] |= mask;
        }
    }
}
