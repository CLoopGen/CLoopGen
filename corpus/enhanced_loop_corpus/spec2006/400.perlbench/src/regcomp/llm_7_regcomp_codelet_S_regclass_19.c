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
    UV local_value;
    char *bm = ((struct regnode_charclass *)ret)->bitmap;
    for (local_value = 0; local_value < 256; local_value += 8) {
        UV base_index = (local_value >> 3) & 31;
        unsigned char mask = 0;
        for (UV offset = 0; offset < 8 && (local_value + offset) < 256; offset++) {
            value = local_value + offset;
            if (((((value) >= 'A' && (value) <= 'Z') || ((value) >= 'a' && (value) <= 'z')) || ((value) >= '0' && (value) <= '9') || (value) == '_')) {
                mask |= (1 << offset);
            }
        }
        bm[base_index] |= mask;
    }
}
