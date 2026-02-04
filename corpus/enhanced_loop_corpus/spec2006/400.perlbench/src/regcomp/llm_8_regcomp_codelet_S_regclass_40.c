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
        if ((((value) == ' ' || (value) == '\t' || (value) == '\n' || (value) == '\r' || (value) == '\f') || (value) == '\v')) {
            int index = (value) >> 3;
            int bit = (value) & 7;
            (((((struct regnode_charclass *)(ret))->bitmap)[index & 31]) |= (1 << bit));
        }
        if ((((value + 1) == ' ' || (value + 1) == '\t' || (value + 1) == '\n' || (value + 1) == '\r' || (value + 1) == '\f') || (value + 1) == '\v')) {
            int index = (value + 1) >> 3;
            int bit = (value + 1) & 7;
            (((((struct regnode_charclass *)(ret))->bitmap)[index & 31]) |= (1 << bit));
        }
    }
}
