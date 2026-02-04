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
    for (value = 0; value < 256; value++) {
        UV shifted = value >> 3;
        UV masked = value & 7;
        UV is_upper = (value >= 65 && value <= 90) ? 1 : 0;
        if (!is_upper) {
            U8 bit = (U8)(1 << masked);
            U16 index = (U16)(shifted & 31);
            (((((struct regnode_charclass *)(ret))->bitmap)[index]) |= bit);
        }
    }
}
