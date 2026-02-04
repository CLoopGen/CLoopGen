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
    // Variant 1: Consecutive memory access with unrolled loop (stride-1 access)
    UV index = 0;
    for (value = 0; value < 256; value += 8) {
        index = (value >> 3) & 31;
        char mask0 = 0, mask1 = 0, mask2 = 0, mask3 = 0,
             mask4 = 0, mask5 = 0, mask6 = 0, mask7 = 0;

        if (!((value + 0) >= 'a' && (value + 0) <= 'z'))
            mask0 |= (1 << ((value + 0) & 7));
        if (!((value + 1) >= 'a' && (value + 1) <= 'z'))
            mask1 |= (1 << ((value + 1) & 7));
        if (!((value + 2) >= 'a' && (value + 2) <= 'z'))
            mask2 |= (1 << ((value + 2) & 7));
        if (!((value + 3) >= 'a' && (value + 3) <= 'z'))
            mask3 |= (1 << ((value + 3) & 7));
        if (!((value + 4) >= 'a' && (value + 4) <= 'z'))
            mask4 |= (1 << ((value + 4) & 7));
        if (!((value + 5) >= 'a' && (value + 5) <= 'z'))
            mask5 |= (1 << ((value + 5) & 7));
        if (!((value + 6) >= 'a' && (value + 6) <= 'z'))
            mask6 |= (1 << ((value + 6) & 7));
        if (!((value + 7) >= 'a' && (value + 7) <= 'z'))
            mask7 |= (1 << ((value + 7) & 7));

        (((struct regnode_charclass *)(ret))->bitmap)[index] |=
            mask0 | mask1 | mask2 | mask3 | mask4 | mask5 | mask6 | mask7;
    }
}
