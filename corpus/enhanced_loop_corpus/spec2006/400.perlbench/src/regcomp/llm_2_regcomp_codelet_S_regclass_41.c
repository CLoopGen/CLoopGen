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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of bit-level addressing, precompute indices and traverse bitmap consecutively
    unsigned char *bm = ((struct regnode_charclass *)ret)->bitmap;
    for (UV byte_idx = 0; byte_idx < 32; byte_idx++) {
        bm[byte_idx] = 0; // Clear first
        for (int bit = 0; bit < 8; bit++) {
            UV value = (byte_idx << 3) | bit;
            if (!(((value) == ' ' || (value) == '\t' || (value) == '\n' || (value) == '\r' || (value) == '\f') || (value) == '\v')) {
                bm[byte_idx] |= (1 << bit);
            }
        }
    }
}
