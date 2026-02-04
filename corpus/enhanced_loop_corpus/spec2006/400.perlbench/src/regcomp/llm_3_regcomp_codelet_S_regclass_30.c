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
    UV mapped_index[256];
    U8 *bitmap = ((struct regnode_charclass *)(ret))->bitmap;
    // Precompute indirect access mapping: reverse the bit position within each byte
    for (UV i = 0; i < 256; i++) {
        UV byte_pos = (i >> 3) & 31;
        UV bit_pos = i & 7;
        UV reversed_bit = 7 - bit_pos;  // Reverse bit order within the byte
        mapped_index[i] = (byte_pos << 3) | reversed_bit;
    }
    for (value = 0; value < 256; value++) {
        if (!((value) < ' ' || (value) == 127)) {
            UV mapped_offset = mapped_index[value];
            bitmap[mapped_offset >> 3] |= (1 << (mapped_offset & 7));
        }
    }
}
