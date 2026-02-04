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
    // Variant 1: Consecutive memory access by precomputing index and iterating over bytes of bitmap directly
    char *bitmap = ((struct regnode_charclass *)ret)->bitmap;
    for (UV byte_idx = 0; byte_idx < 32; byte_idx++) {
        U8 val_base = byte_idx << 3;  // Start value for this byte
        U8 mask = 1;
        for (U8 bit = 0; bit < 8; bit++) {
            UV value = val_base | bit;
            if (((value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z')))
                bitmap[byte_idx] |= mask;
            mask <<= 1;
        }
    }
}
