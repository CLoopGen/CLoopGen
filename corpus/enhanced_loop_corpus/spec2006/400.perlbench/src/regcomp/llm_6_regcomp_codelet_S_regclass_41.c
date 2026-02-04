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
    UV temp_value;
    for (temp_value = 0; temp_value < 256; temp_value++) {
        UV index = temp_value;
        if (!(((index) == ' ' || (index) == '\t' || (index) == '\n' || (index) == '\r' || (index) == '\f') || (index) == '\v')) {
            U8 shift = (U8)(index & 7);
            U8 bit = (U8)(1 << shift);
            int byte_index = ((index) >> 3) & 31;
            (((((struct regnode_charclass *)(ret))->bitmap)[byte_index]) |= bit);
        }
    }
}
