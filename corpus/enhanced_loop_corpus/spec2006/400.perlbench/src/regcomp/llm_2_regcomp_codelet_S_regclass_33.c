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
    // Variant 1: Consecutive memory access by precomputing index and unrolling the loop in strides of 8
    // This variant reorganizes access to bitmap to be more sequential by processing byte indices directly
    UV start = '9' + 1;
    UV end = 256;
    U8* bitmap = ((struct regnode_charclass *)(ret))->bitmap;

    // Align start to byte boundary and process bit-by-bit only at edges if needed
    // Here we assume no alignment issues and process all values from start to end
    for (UV byte_idx = (start >> 3); byte_idx <= ((end - 1) >> 3); byte_idx++) {
        UV base_value = byte_idx << 3;
        unsigned char byte_mask = 0;
        for (int bit = 0; bit < 8; bit++) {
            UV value = base_value | bit;
            if (value >= start && value < end) {
                byte_mask |= (1 << bit);
            }
        }
        bitmap[byte_idx & 31] |= byte_mask;
    }
}
