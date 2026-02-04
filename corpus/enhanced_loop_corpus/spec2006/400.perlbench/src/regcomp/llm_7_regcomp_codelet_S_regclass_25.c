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
    U8 local_bitmap[32] = {0};
    for (UV value = 0; value < 128; value++) {
        UV idx = value >> 3;
        UV bit = value & 7;
        local_bitmap[idx] |= (1 << bit);
    }
    for (UV i = 0; i < 32; i++) {
        (((struct regnode_charclass *)ret)->bitmap[i]) = local_bitmap[i];
    }
}
