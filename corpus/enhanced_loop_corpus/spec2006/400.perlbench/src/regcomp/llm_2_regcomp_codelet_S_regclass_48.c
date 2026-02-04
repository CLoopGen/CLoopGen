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
    // Instead of random access based on value, we restructure to access bitmap sequentially
    // by grouping values by their byte index in the bitmap (i.e., by value >> 3)
    unsigned char temp_bitmap[32] = {0}; // Local buffer for consecutive updates

    for (UV group = 0; group < 32; group++) {
        UV base_value = group << 3; // Starting value for this byte group
        U8 mask = 0;
        for (int bit = 0; bit < 8; bit++) {
            UV value = base_value | bit;
            if (((value >= '0' && value <= '9') || (value >= 'a' && value <= 'f') || (value >= 'A' && value <= 'F'))) {
                mask |= (1 << bit);
            }
        }
        temp_bitmap[group] = mask;
    }

    // Copy result to target bitmap using consecutive writes
    for (int i = 0; i < 32; i++) {
        (((struct regnode_charclass *)(ret))->bitmap)[i] = temp_bitmap[i];
    }
}
