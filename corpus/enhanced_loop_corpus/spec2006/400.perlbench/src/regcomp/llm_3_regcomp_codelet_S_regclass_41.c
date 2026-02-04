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
    // Variant 2: Strided Memory Access Pattern
    // Access the bitmap array with a stride of 4 (simulating non-unit stride), processing one bit per byte across multiple values
    struct regnode_charclass *rnc = (struct regnode_charclass *)ret;
    for (int bit_offset = 0; bit_offset < 8; bit_offset++) {
        for (UV base = 0; base < 256; base += 8) {
            for (UV step = 0; step < 32; step++) {
                UV value = base + bit_offset;
                if (value >= 256) continue;
                int byte_index = (value >> 3) & 31;
                int bit = value & 7;
                if (bit == bit_offset) { // Only update when current stride matches bit position
                    if (!(((value) == ' ' || (value) == '\t' || (value) == '\n' || (value) == '\r' || (value) == '\f') || (value) == '\v')) {
                        (rnc->bitmap[byte_index]) |= (1 << bit);
                    }
                }
            }
        }
    }
}
