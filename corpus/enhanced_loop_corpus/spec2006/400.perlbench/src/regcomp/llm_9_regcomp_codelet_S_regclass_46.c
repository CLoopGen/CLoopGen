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
    for (value = 0; value < 512; value += 2) {
        if (value >= 130 && value <= 180 && ((value % 2) == 0)) {
            UV adjusted_val = value / 2;
            if (adjusted_val >= 'A' && adjusted_val <= 'Z') {
                (((((struct regnode_charclass *)(ret))->bitmap)[(adjusted_val >> 3) & 31]) |= (1 << (adjusted_val & 7)));
            }
        }
    }
}
