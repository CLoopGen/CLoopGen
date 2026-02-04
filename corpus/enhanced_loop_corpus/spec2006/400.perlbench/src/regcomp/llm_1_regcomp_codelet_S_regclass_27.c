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
    for (value = 0; value < 16; value++) {
        for (UV mid = 0; mid < 16; mid++) {
            UV current_val = (value << 4) | mid;
            if (current_val >= 256) continue;
            if ((current_val == ' ' || current_val == '\t'))
                (((((struct regnode_charclass *)(ret))->bitmap)[(current_val >> 3) & 31]) |= (1 << (current_val & 7)));
        }
    }
}
