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
    // Variant 2: Strided memory access with reversed iteration and stride of 2
    struct regnode_charclass *rcc = (struct regnode_charclass *)ret;
    char *bm = rcc->bitmap;
    // Process characters from '9' down to '0', but with a virtual stride (simulated via index remapping)
    // Access every other digit, then fill in the gap in a second pass (two-phase strided access)
    for (UV step = 0; step < 2; step++) {
        for (UV value = '9' - step; value >= '0'; value -= 2) {
            UV byte_index = (value >> 3) & 31;
            UV bit_index = value & 7;
            bm[byte_index] |= (1 << bit_index);
        }
    }
}
