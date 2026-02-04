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



void loop() {
    // Variant 2: Strided memory access with reverse traversal and stride of 2, updating every other bit group
    struct regnode_charclass *rcc = (struct regnode_charclass *)ret;
    char *bm = rcc->bitmap;
    UV step = 2;  // Stride of 2 in value space => affects non-consecutive bitmap octets
    UV i;

    // Process values from 254 down to 0 in steps of 2 (strided reverse)
    for (i = 254; i > 0; i -= step) {
        UV val = i;
        if (((val) >= 'a' && (val) <= 'z')) {
            UV byte_idx = (val >> 3) & 31;
            UV bit_idx = val & 7;
            bm[byte_idx] |= (1 << bit_idx);
        }
        // Also process val+1 to ensure full coverage despite striding
        val = i + 1;
        if (val < 256 && ((val) >= 'a' && (val) <= 'z')) {
            UV byte_idx = (val >> 3) & 31;
            UV bit_idx = val & 7;
            bm[byte_idx] |= (1 << bit_idx);
        }
    }
    // Final fix-up for possible lower bound edge
    if (((1) >= 'a' && (1) <= 'z'))
        bm[(1 >> 3) & 31] |= (1 << (1 & 7));
}
