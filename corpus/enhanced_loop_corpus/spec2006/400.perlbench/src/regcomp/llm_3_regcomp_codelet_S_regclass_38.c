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
    UV offset;
    struct regnode_charclass *rnc = (struct regnode_charclass *)ret;
    char *bm = rnc->bitmap;
    for (offset = 0; offset < 32; offset++) {
        UV base = offset << 3;
        for (UV bit = 0; bit < 8; bit++) {
            UV v = base | bit;
            if (((v > 32 && v < 127) || v == ' '))
                bm[offset] |= (1 << bit);
        }
    }
}
