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
    UV local_value = value;
    for (; local_value < 256; local_value += 2) {
        UV v1 = local_value;
        UV v2 = local_value + 1;
        int cond1 = !((v1) >= 'a' && (v1) <= 'z');
        int cond2 = !((v2) >= 'a' && (v2) <= 'z');
        if (cond1)
            (((((struct regnode_charclass *)(ret))->bitmap)[(v1 >> 3) & 31]) |= (1 << (v1 & 7)));
        if (cond2 && v2 < 256)
            (((((struct regnode_charclass *)(ret))->bitmap)[(v2 >> 3) & 31]) |= (1 << (v2 & 7)));
    }
    value = local_value;
}
