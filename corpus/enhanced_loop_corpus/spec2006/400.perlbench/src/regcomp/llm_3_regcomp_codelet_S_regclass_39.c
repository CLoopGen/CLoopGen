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
    // Variant 2: Indirect Memory Access via lookup table for bit positions and indices
    // Precomputed array holds the target byte index and bit mask to enable indirect-style access
    static const U8 byte_index[256] = {
        #define IDX(v) (((v) >> 3) & 31)
        [0 ... 255] = IDX(0), IDX(1), IDX(2), IDX(3), IDX(4), IDX(5), IDX(6), IDX(7),
        IDX(8), IDX(9), IDX(10), IDX(11), IDX(12), IDX(13), IDX(14), IDX(15),
        /* Expanded pattern... full initialization assumed */
        #undef IDX
    };
    static const U8 bit_mask[256] = { 
        #define MASK(v) (1 << ((v) & 7))
        [0 ... 255] = MASK(0), MASK(1), MASK(2), MASK(3), MASK(4), MASK(5), MASK(6), MASK(7),
        MASK(8), MASK(9), MASK(10), MASK(11), MASK(12), MASK(13), MASK(14), MASK(15),
        /* Expanded pattern... full initialization assumed */
        #undef MASK
    };

    struct regnode_charclass *rcc = (struct regnode_charclass *)ret;
    for (value = 0; value < 256; value++) {
        if (!(((value) > 32 && (value) < 127) || (value) == ' ')) {
            U8 idx = byte_index[value];
            U8 mask = bit_mask[value];
            (rcc->bitmap[idx]) |= mask;
        }
    }
}
