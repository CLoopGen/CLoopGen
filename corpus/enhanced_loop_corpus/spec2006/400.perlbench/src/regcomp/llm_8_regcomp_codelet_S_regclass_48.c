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
    UV step = 2;
    for (value = 0; value < 256; value += step) {
        for (UV offset = 0; offset < step && (value + offset) < 256; offset++) {
            UV val = value + offset;
            if (((val >= '0' && val <= '9') || (val >= 'a' && val <= 'f') || (val >= 'A' && val <= 'F')))
                ((((struct regnode_charclass *)(ret))->bitmap)[(val >> 3) & 31]) |= (1 << (val & 7));
        }
    }
}
