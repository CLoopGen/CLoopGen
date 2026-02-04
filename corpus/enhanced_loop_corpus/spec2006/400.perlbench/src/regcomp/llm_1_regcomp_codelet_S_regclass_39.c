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
    for (UV outer = 0; outer < 4; outer++) {
        for (UV mid = 0; mid < 8; mid++) {
            for (UV inner = 0; inner < 8; inner++) {
                UV value = (outer << 8) | (mid << 3) | inner;
                if (value >= 256) continue;
                if (!(((value) > 32 && (value) < 127) || (value) == ' '))
                    (((((struct regnode_charclass *)(ret))->bitmap)[(value >> 3) & 31]) |= (1 << ((value) & 7)));
            }
        }
    }
}
