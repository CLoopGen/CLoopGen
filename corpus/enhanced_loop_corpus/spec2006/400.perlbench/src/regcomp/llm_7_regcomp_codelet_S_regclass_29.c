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
    UV local_value = value;
    char temp_bitmap[32] = {0};
    for (local_value = 0; local_value < 256; local_value++) {
        if ((local_value < ' ' || local_value == 127)) {
            U16 idx = (local_value >> 3) & 31;
            U8 bit = local_value & 7;
            temp_bitmap[idx] |= (1 << bit);
        }
    }
    for (int i = 0; i < 32; i++) {
        (((struct regnode_charclass *)ret)->bitmap[i]) |= temp_bitmap[i];
    }
    value = local_value;
}
