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
    // Variant 1: Consecutive memory access by precomputing index and bit operations
    // Instead of random access based on 'value', we traverse the bitmap array sequentially
    // and compute which 'value' corresponds to each byte/bit position.
    UV byte_idx, bit_idx;
    for (byte_idx = 0; byte_idx < 32; byte_idx++) {
        for (bit_idx = 0; bit_idx < 8; bit_idx++) {
            UV value = (byte_idx << 3) | bit_idx;
            if (!(((value) >= '0' && (value) <= '9') || ((value) >= 'a' && (value) <= 'f') || ((value) >= 'A' && (value) <= 'F')))
                (((((struct regnode_charclass *)(ret))->bitmap)[byte_idx]) |= (1 << bit_idx));
        }
    }
}
