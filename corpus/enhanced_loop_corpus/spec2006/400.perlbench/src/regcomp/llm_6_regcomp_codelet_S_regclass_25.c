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
    for (temp_value = 0; temp_value < 128; temp_value++) {
        UV index = temp_value >> 3;
        UV bit_pos = temp_value & 7;
        U8 mask = 1 << bit_pos;
        ((struct regnode_charclass *)ret)->bitmap[index & 31] |= mask;
    }
}
