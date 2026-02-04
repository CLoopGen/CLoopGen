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
    UV local_value;
    char *bm = ((struct regnode_charclass *)(ret))->bitmap;
    for (local_value = 0; local_value < 256; local_value += 2) {
        UV val1 = local_value;
        UV val2 = local_value + 1;
        int idx1 = (val1 >> 3) & 31;
        int idx2 = (val2 >> 3) & 31;
        if ((val1 == ' ' || val1 == '\t'))
            bm[idx1] |= (1 << (val1 & 7));
        if ((val2 == ' ' || val2 == '\t') && val2 < 256)
            bm[idx2] |= (1 << (val2 & 7));
    }
}
