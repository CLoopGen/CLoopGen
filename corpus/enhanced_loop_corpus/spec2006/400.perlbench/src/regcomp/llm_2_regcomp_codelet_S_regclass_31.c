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
    // Variant 1: Consecutive memory access by precomputing index and unrolling in steps
    UV start = '0';
    UV end = '9';
    struct regnode_charclass *rcc = (struct regnode_charclass *)ret;
    char *bm = rcc->bitmap;
    for (UV i = start; i <= end; i++) {
        UV index = i - '0'; // Normalize to 0-based index for consecutive access pattern
        UV byte_pos = index >> 3;
        UV bit_pos = index & 7;
        bm[byte_pos] |= (1 << bit_pos);
    }
}
