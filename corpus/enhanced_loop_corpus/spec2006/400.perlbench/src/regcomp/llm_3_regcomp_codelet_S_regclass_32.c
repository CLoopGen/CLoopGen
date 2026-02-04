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
    // Variant 2: Strided memory access — process every 4th bit first, then stride through
    char *bm = ((struct regnode_charclass *)ret)->bitmap;
    for (int stride = 0; stride < 8; stride++) {
        for (UV value = stride; value < '0'; value += 8) {
            bm[value >> 3] |= (1 << (value & 7));
        }
    }
}
