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
    // Variant 1: Consecutive memory access with precomputed index and unrolled-like byte handling
    UV base_index;
    U8 bit;
    for (value = 0; value < 256; value += 8) {
        base_index = (value >> 3) & 31;
        struct regnode_charclass *rcc = (struct regnode_charclass *)ret;
        char *bm = &rcc->bitmap[base_index];
        
        for (int offset = 0; offset < 8 && (value + offset) < 256; offset++) {
            UV val = value + offset;
            if ((val == ' ' || val == '\t')) {
                bit = (1 << (val & 7));
                bm[0] |= bit;
            }
        }
    }
}
