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
    UV limit = 64;
    for (UV outer = 0; outer < limit; outer++) {
        for (UV inner = 0; inner < 4; inner++) {
            UV value = (outer << 2) | inner;
            UV masked_val = value & 255;
            int is_alnum_or_underscore = (((masked_val >= 'A' && masked_val <= 'Z') ||
                                          (masked_val >= 'a' && masked_val <= 'z') ||
                                          (masked_val >= '0' && masked_val <= '9') ||
                                           masked_val == '_'));
            if (!is_alnum_or_underscore) {
                U8 shift_amount = (U8)(masked_val & 7);
                U8 bit_index = (U8)((masked_val >> 3) & 31);
                (((((struct regnode_charclass *)(ret))->bitmap)[bit_index]) |= (1ULL << shift_amount));
            }
        }
    }
}
