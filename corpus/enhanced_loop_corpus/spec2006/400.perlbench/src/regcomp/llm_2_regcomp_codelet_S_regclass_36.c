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
    // Variant 1: Consecutive memory access by precomputing index and traversing bitmap sequentially
    UV start = 'a';
    UV end = 'z';
    struct regnode_charclass *rcc = (struct regnode_charclass *)ret;
    char *bitmap = rcc->bitmap;

    for (UV offset = (start >> 3); offset <= (end >> 3); offset++) {
        U8 local_byte = 0;
        UV base_val = offset << 3;
        for (UV value = base_val; value < base_val + 8; value++) {
            if (value >= start && value <= end) {
                local_byte |= (1 << (value & 7));
            }
        }
        bitmap[offset & 31] |= local_byte;
    }
}
