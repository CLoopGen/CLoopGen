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
    // Variant 2: Strided memory access with reverse traversal and stride of 2
    struct regnode_charclass *node = (struct regnode_charclass *)ret;
    for (UV value = 254; value >= 128; value -= 2) {
        int index = (value >> 3) & 31;
        int bit = value & 7;
        node->bitmap[index] |= (1 << bit);
    }
}
