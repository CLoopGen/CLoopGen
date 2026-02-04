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
    UV segment_start;
    for (segment_start = 0; segment_start < 256; segment_start += 64) {
        UV value_end = segment_start + 64;
        for (value = segment_start; value < value_end; value++) {
            if (!((value) < ' ' || (value) == 127))
                (((((struct regnode_charclass *)(ret))->bitmap)[((value) >> 3) & 31]) |= (1 << ((value) & 7)));
        }
    }
}
