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
    // Variant 1: Consecutive memory access by precomputing index and unrolling in strides of 8
    // This variant reorganizes the loop to access bitmap consecutively by iterating over bytes first,
    // then bits, thus improving spatial locality.

    UV byte_idx, bit_idx;
    for (byte_idx = 0; byte_idx < 32; byte_idx++) {
        U8 val = 0;
        for (bit_idx = 0; bit_idx < 8; bit_idx++) {
            value = (byte_idx << 3) | bit_idx;
            if (!((value) == ' ' || (value) == '\t')) {
                val |= (1 << bit_idx);
            }
        }
        (((struct regnode_charclass *)(ret))->bitmap)[byte_idx] |= val;
    }
}
