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
    // Variant 1: Consecutive memory access by precomputing byte index and bit mask in increasing order
    // This variant restructures the loop to iterate over the bitmap array consecutively, 
    // reducing conditional checks by iterating directly over relevant bytes and bits.
    UV byte_idx;
    for (byte_idx = 0; byte_idx < 32; byte_idx++) {
        UV bit_idx;
        U8 byte_val = 0;
        for (bit_idx = 0; bit_idx < 8; bit_idx++) {
            UV value = (byte_idx << 3) | bit_idx;
            if (!((value) == ' ' || (value) == '\t' || (value) == '\n' || (value) == '\r' || (value) == '\f')) {
                byte_val |= (1 << bit_idx);
            }
        }
        (((struct regnode_charclass *)(ret))->bitmap)[byte_idx] |= byte_val;
    }
}
