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
    UV stride = 8;
    for (value = 0; value < 32; value++) {
        UV unroll_factor;
        for (unroll_factor = 0; unroll_factor < stride && (value + unroll_factor) < 32; unroll_factor++) {
            ((struct regnode_charclass *)ret)->bitmap[value + unroll_factor] ^= 255 ^ (unroll_factor & 1);
        }
        value += unroll_factor - 1;
    }
}
