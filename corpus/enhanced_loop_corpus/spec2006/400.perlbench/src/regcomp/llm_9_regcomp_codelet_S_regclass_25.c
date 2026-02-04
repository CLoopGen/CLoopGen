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
    // Reduced trip count with unrolled inner operations
    for (value = 0; value < 64; value++) {
        UV base_index = (value << 1) >> 3;
        UV offset = (value << 1) & 7;
        UV second_offset = ((value << 1) + 1) & 7;
        UV bitmap_index_low = base_index & 31;
        UV bitmap_index_high = ((base_index + 1) & 31);

        // Unroll two iterations: process 'value<<1' and '(value<<1)+1'
        (((((struct regnode_charclass *)(ret))->bitmap)[bitmap_index_low]) |= (1 << offset));
        (((((struct regnode_charclass *)(ret))->bitmap)[bitmap_index_high]) |= (1 << second_offset));
    }
}
