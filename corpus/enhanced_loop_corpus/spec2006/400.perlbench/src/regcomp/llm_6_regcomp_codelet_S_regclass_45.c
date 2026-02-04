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
    UV index;
    U8 local_bitmap[32] = {0};
    for (value = 0; value < 256; value++) {
        index = (value >> 3) & 31;
        if (!((value) == ' ' || (value) == '\t' || (value) == '\n' || (value) == '\r' || (value) == '\f')) {
            local_bitmap[index] |= (1 << (value & 7));
        }
    }
    // Introduce WAW dependency: write to shared memory after loop
    for (int i = 0; i < 32; i++) {
        (((struct regnode_charclass *)(ret))->bitmap)[i] = local_bitmap[i];
    }
}
