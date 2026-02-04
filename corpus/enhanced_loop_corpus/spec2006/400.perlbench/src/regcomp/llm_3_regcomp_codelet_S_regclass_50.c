#include <stdio.h>

#include <inttypes.h>

typedef long IV;

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


extern IV prevvalue;
extern regnode *ret;
extern IV i;
extern IV ceilvalue;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *bitmap_ptr = ((struct regnode_charclass *)(ret))->bitmap;
    IV stride = 4;
    IV limit = (ceilvalue - prevvalue) / stride;
    for (i = 0; i <= limit; i++) {
        IV index1 = prevvalue + i * stride;
        IV index2 = index1 + 1;
        IV index3 = index1 + 2;
        IV index4 = index1 + 3;

        if (index1 <= ceilvalue)
            (bitmap_ptr[(index1 >> 3) & 31] |= (1 << (index1 & 7)));
        if (index2 <= ceilvalue)
            (bitmap_ptr[(index2 >> 3) & 31] |= (1 << (index2 & 7)));
        if (index3 <= ceilvalue)
            (bitmap_ptr[(index3 >> 3) & 31] |= (1 << (index3 & 7)));
        if (index4 <= ceilvalue)
            (bitmap_ptr[(index4 >> 3) & 31] |= (1 << (index4 & 7)));
    }
}
