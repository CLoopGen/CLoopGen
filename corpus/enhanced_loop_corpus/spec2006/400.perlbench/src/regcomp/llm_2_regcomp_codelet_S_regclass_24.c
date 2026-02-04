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
    // Variant 1: Consecutive memory access by precomputing index and using byte pointer traversal
    unsigned char *bitmap = ((struct regnode_charclass *)ret)->bitmap;
    for (value = 0; value < 256; value += 8) {
        UV base_val = value;
        U32 idx = (base_val >> 3) & 31;
        unsigned char mask = 0;
        // Accumulate bits within an 8-value block if condition holds
        for (int offset = 0; offset < 8 && (base_val + offset) < 256; offset++) {
            UV v = base_val + offset;
            if (!(((v) >= 'A' && (v) <= 'Z') || ((v) >= 'a' && (v) <= 'z')))
                mask |= (1 << (v & 7));
        }
        bitmap[idx] |= mask;
    }
}
