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
    UV step = 4;
    for (value = 0; value < 256; value += step) {
        for (UV inner = 0; inner < step && (value + inner) < 256; inner++) {
            UV val = value + inner;
            if (!(((val) == ' ' || (val) == '\t' || (val) == '\n' || (val) == '\r' || (val) == '\f') || (val) == '\v')) {
                char* bm = &(((struct regnode_charclass *)(ret))->bitmap)[(val >> 3) & 31];
                *bm |= (1 << (val & 7));
            }
        }
    }
}
