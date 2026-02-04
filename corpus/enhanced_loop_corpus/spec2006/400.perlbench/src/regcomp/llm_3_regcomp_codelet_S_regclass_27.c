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
    // Variant 2: Strided memory access - process only every 4th value, then handle alignment
    struct regnode_charclass *rcc = (struct regnode_charclass *)ret;
    char *bm = rcc->bitmap;
    int stride = 4;
    UV aligned_value;

    // Handle all values using strided iteration, then fix remainder
    for (aligned_value = 0; aligned_value < 256; aligned_value += stride) {
        for (int step = 0; step < stride; step++) {
            UV value = aligned_value + step;
            if (value >= 256) break;
            if ((value == ' ' || value == '\t')) {
                UV index = (value >> 3) & 31;
                bm[index] |= (1 << (value & 7));
            }
        }
    }
}
