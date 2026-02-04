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
    UV limit = '0' * 4;
    for (value = 0; value < limit; value++) {
        UV adjusted_value = value >> 2;
        if (adjusted_value < '0') {
            (((((struct regnode_charclass *)(ret))->bitmap)[(adjusted_value >> 3) & 31]) |= (1 << (adjusted_value & 7)));
        }
    }
}
