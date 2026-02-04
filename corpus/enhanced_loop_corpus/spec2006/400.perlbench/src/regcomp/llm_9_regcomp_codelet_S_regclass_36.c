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
    UV step;
    for (value = 'a'; value <= 'z'; value++) {
        step = value;
        for (int unroll = 0; unroll < 4; unroll++) {
            UV adjusted = step + unroll * 64;
            if (adjusted < 256) {
                UV index = (adjusted >> 3) & 31;
                UV bit = adjusted & 7;
                (((((struct regnode_charclass *)(ret))->bitmap)[index]) |= (1 << bit));
            }
        }
    }
}
