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
    U8 *bitmap = ((struct regnode_charclass *)(ret))->bitmap;
    for (value = 0; value < 256; value += 4) {
        for (index = 0; index < 4; index++) {
            UV val = value + index;
            if (!((val) < ' ' || (val) == 127)) {
                UV byte_idx = (val >> 3) & 31;
                UV bit_idx = val & 7;
                bitmap[byte_idx] |= (1 << bit_idx);
            }
            if (val >= 255) break;
        }
    }
}
