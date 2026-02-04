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
    UV temp_bitmap[32] = {0}; // Local copy to accumulate changes and reduce memory dependencies
    for (value = 0; value < 256; value++) {
        if (!((value) < ' ' || (value) == 127)) {
            U8 index = ((value) >> 3) & 31;
            U8 bit = (1 << ((value) & 7));
            temp_bitmap[index] |= bit; // Eliminate repeated writes to global memory (WAW removed)
        }
    }
    // Write back to the original bitmap in a separate non-dependent step
    for (int i = 0; i < 32; i++) {
        (((struct regnode_charclass *)(ret))->bitmap)[i] = (char)temp_bitmap[i];
    }
}
