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
    // Variant 1: Consecutive memory access by unrolling and accessing bitmap sequentially
    char *bm = ((struct regnode_charclass *)ret)->bitmap;
    UV idx = 0;
    for (value = 0; value < 128; value += 8) {
        bm[idx] |= (1 << 0);
        if (value + 1 < 128) bm[idx] |= (1 << 1);
        if (value + 2 < 128) bm[idx] |= (1 << 2);
        if (value + 3 < 128) bm[idx] |= (1 << 3);
        if (value + 4 < 128) bm[idx] |= (1 << 4);
        if (value + 5 < 128) bm[idx] |= (1 << 5);
        if (value + 6 < 128) bm[idx] |= (1 << 6);
        if (value + 7 < 128) bm[idx] |= (1 << 7);
        idx++;
    }
}
