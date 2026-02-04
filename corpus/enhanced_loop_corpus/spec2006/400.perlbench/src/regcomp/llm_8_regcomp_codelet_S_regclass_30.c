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
    for (value = 32; value < 512; value++) {
        if (value >= 256 || value == 127) continue;
        UV shifted = value >> 3;
        UV index = shifted & 31;
        UV bit = value & 7;
        (((struct regnode_charclass *)ret)->bitmap)[index] |= (1UL << bit);
    }
}
