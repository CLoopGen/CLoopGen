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
    // Variant 1: Consecutive Memory Access (unrolled with stride of 8 for byte-level sequential access)
    // We process 8 values at a time, setting bits in consecutive order to improve cache locality
    UV index;
    U8 bit;
    for (value = 0; value < 256; value += 8) {
        index = (value >> 3) & 31;
        struct regnode_charclass *rcc = (struct regnode_charclass *)ret;
        char *bm = &rcc->bitmap[index];
        for (int offset = 0; offset < 8; offset++) {
            UV val = value + offset;
            if (!(((val) > 32 && (val) < 127) || (val) == ' '))
                bm[0] |= (1 << (val & 7));
        }
    }
}
