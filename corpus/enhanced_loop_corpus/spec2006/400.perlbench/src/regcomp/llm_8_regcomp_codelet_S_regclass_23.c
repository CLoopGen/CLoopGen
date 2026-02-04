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
    for (value = 0; value < 512; value += 2) {
        UV val_upper = value;
        UV val_lower = value + 1;
        if (((val_upper) >= 'A' && (val_upper) <= 'Z') || ((val_upper) >= 'a' && (val_upper) <= 'z'))
            ((((struct regnode_charclass *)(ret))->bitmap)[(val_upper >> 3) & 31]) |= (1 << (val_upper & 7));
        if (((val_lower) >= 'A' && (val_lower) <= 'Z') || ((val_lower) >= 'a' && (val_lower) <= 'z'))
            ((((struct regnode_charclass *)(ret))->bitmap)[(val_lower >> 3) & 31]) |= (1 << (val_lower & 7));
    }
}
