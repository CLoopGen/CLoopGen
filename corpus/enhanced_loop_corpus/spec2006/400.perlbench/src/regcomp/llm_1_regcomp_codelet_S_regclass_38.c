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
    UV value1, value2;
    for (value1 = 0; value1 < 16; value1++) {
        for (value2 = 0; value2 < 16; value2++) {
            UV combined = (value1 << 4) | value2;
            if (combined >= 256) continue;
            if ((((combined) > 32 && (combined) < 127) || (combined) == ' '))
                (((((struct regnode_charclass *)(ret))->bitmap)[(combined >> 3) & 31]) |= (1 << (combined & 7)));
        }
    }
}
