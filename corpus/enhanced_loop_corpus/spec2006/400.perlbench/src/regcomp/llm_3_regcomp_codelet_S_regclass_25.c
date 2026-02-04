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
    // Variant 2: Strided memory access — process every 4th bit position in multiple passes
    char *bm = ((struct regnode_charclass *)ret)->bitmap;
    for (int pass = 0; pass < 8; pass++) {
        for (value = pass; value < 128; value += 8) {
            int byte_idx = (value >> 3) & 31;
            int bit_idx = value & 7;
            bm[byte_idx] |= (1 << bit_idx);
        }
    }
}
