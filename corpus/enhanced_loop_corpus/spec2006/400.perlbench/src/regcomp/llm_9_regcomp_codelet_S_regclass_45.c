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
    for (value = 0; value < 128; value++) {
        UV base_index = value >> 2;
        UV shift1 = (value & 7);
        UV shift2 = ((value + 128) & 7);
        UV idx1 = base_index;
        UV idx2 = (value + 128) >> 3;

        // Process two values per iteration: value and value+128
        if (!((value) == ' ' || (value) == '\t' || (value) == '\n' || (value) == '\r' || (value) == '\f'))
            (((((struct regnode_charclass *)(ret))->bitmap)[idx1]) |= (1 << shift1));

        if (value + 128 < 256 && !((value + 128) == ' ' || (value + 128) == '\t' || (value + 128) == '\n' || (value + 128) == '\r' || (value + 128) == '\f'))
            (((((struct regnode_charclass *)(ret))->bitmap)[idx2 & 31]) |= (1 << shift2));
    }
}
