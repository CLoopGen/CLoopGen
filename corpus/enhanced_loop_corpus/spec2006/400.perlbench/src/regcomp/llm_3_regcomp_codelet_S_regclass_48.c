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
    // Variant 2: Strided memory access - process all values with same bit position first
    // Instead of iterating by value, iterate by bit position (0-7), then stride through bytes
    // This creates a strided access pattern across the bitmap array
    unsigned char temp_bitmap[32] = {0};

    for (int bit = 0; bit < 8; bit++) {
        for (UV byte_idx = 0; byte_idx < 32; byte_idx++) {
            UV value = (byte_idx << 3) | bit; // Compute actual character value
            if (value < 256 && 
                ((value >= '0' && value <= '9') || 
                 (value >= 'a' && value <= 'f') || 
                 (value >= 'A' && value <= 'F'))) {
                temp_bitmap[byte_idx] |= (1 << bit);
            }
        }
    }

    // Apply the accumulated bitmap
    for (int i = 0; i < 32; i++) {
        (((struct regnode_charclass *)(ret))->bitmap)[i] = temp_bitmap[i];
    }
}
