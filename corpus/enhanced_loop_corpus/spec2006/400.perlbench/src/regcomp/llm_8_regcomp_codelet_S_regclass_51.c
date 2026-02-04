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


extern const unsigned char PL_fold[];
extern UV value;
extern regnode *ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (value = 0; value < 256; value += 2) {
        UV fold1 = PL_fold[value];
        if ((((((struct regnode_charclass *)(ret))->bitmap)[(value >> 3) & 31]) & (1 << (value & 7)))) {
            if (fold1 != value)
                (((((struct regnode_charclass *)(ret))->bitmap)[(fold1 >> 3) & 31]) |= (1 << (fold1 & 7)));
        }
        if (value + 1 < 256) {
            UV fold2 = PL_fold[value + 1];
            if ((((((struct regnode_charclass *)(ret))->bitmap)[((value + 1) >> 3) & 31]) & (1 << ((value + 1) & 7)))) {
                if (fold2 != value + 1)
                    (((((struct regnode_charclass *)(ret))->bitmap)[(fold2 >> 3) & 31]) |= (1 << (fold2 & 7)));
            }
        }
    }
}
