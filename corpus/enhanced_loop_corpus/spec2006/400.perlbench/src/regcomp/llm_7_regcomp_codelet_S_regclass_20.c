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
    UV v;
    // Eliminate loop-carried dependencies by unrolling and using independent accumulators
    U32 temp_bitmap[32] = {0}; // Local working copy to remove RAW/WAW across iterations
    for (v = 0; v < 256; v += 8) {
        #pragma unroll 8
        for (int step = 0; step < 8 && (v + step) < 256; step++) {
            UV value = v + step;
            UV idx = (value) >> 3 & 31;
            U8 bit = (1 << ((value) & 7));
            if (!((((value) >= 'A' && (value) <= 'Z') || ((value) >= 'a' && (value) <= 'z')) || ((value) >= '0' && (value) <= '9') || (value) == '_')) {
                temp_bitmap[idx] |= bit; // No inter-iteration dependency
            }
        }
    }
    // Commit local changes in a final independent loop
    for (int i = 0; i < 32; i++) {
        (((struct regnode_charclass *)(ret))->bitmap)[i] |= temp_bitmap[i];
    }
}
