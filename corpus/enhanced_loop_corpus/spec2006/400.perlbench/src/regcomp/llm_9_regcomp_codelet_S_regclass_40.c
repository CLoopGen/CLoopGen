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
        UV val1 = value;
        UV val2 = value + 128;
        int idx1 = val1 >> 3;
        int idx2 = val2 >> 3;
        int bit1 = val1 & 7;
        int bit2 = val2 & 7;
        char cond1 = ((val1 == ' ' || val1 == '\t' || val1 == '\n' || val1 == '\r' || val1 == '\f' || val1 == '\v'));
        char cond2 = ((val2 == ' ' || val2 == '\t' || val2 == '\n' || val2 == '\r' || val2 == '\f' || val2 == '\v'));
        if (cond1) {
            (((((struct regnode_charclass *)(ret))->bitmap)[idx1 & 31]) |= (1 << bit1));
        }
        if (cond2 && val2 < 256) {
            (((((struct regnode_charclass *)(ret))->bitmap)[idx2 & 31]) |= (1 << bit2));
        }
    }
}
