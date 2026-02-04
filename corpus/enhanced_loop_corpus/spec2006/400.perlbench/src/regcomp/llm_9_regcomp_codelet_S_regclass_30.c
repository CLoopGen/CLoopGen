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
        UV val1 = value;
        UV val2 = value + 1;
        if (!(val1 < ' ' || val1 == 127)) {
            (((((struct regnode_charclass *)(ret))->bitmap)[(val1 >> 3) & 31])) |= (1 << (val1 & 7));
        }
        if (val2 < 256 && !(val2 < ' ' || val2 == 127)) {
            (((((struct regnode_charclass *)(ret))->bitmap)[(val2 >> 3) & 31])) |= (1 << (val2 & 7));
        }
    }
}
